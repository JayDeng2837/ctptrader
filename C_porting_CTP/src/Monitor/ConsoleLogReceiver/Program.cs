using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Threading;
using System.Threading.Tasks;
using NetMQ;
using lcts;

namespace ConsoleLogReceiver
{

    class Program
    {
        public static bool isRun = true;

        public delegate void GetDataHandler(Byte[] message);
        public static event GetDataHandler OnGetData;

        /// <summary>
        /// NetMQ 订阅模式
        /// </summary>
        public static void Start()
        {
            OnGetData += new GetDataHandler(ProcessData);
            long recv_timeout = TimeSpan.TicksPerSecond;
            using (var context = NetMQContext.Create())
            using (var subscriber = context.CreateSubscriberSocket())
            {
                subscriber.Connect("tcp://127.0.0.1:8888");
                Console.WriteLine("after connection");
                subscriber.Subscribe("");
                while (isRun)
                {

                    try
                    {
                        Byte[] pb = null;
                        NetMQMessage msg = subscriber.ReceiveMessage(new TimeSpan(recv_timeout));

                        if (null == msg)
                        {
                            /*
                            Console.WriteLine(String.Format(">> RECV >> TIMEOUT({0}s)",
                                              recv_timeout / TimeSpan.TicksPerSecond));
                             * */
                            throw new Exception("timeout");
                        }

                        int msgId = -1;

                       OnGetData(msg[msg.FrameCount - 1].Buffer);
                    }
                    catch (Exception ex)
                    {
                        //Console.WriteLine("got timeout Exception!");
                    }
                }
            }
        }

        public static void ProcessData(Byte[] msg)
        {
            string msg_str = Encoding.ASCII.GetString(msg);
            //Console.WriteLine(msg_str);

            try
            {
                LogInfo li = LogInfo.ParseFrom(msg);

                if (li != null)
                {
                    Console.WriteLine(li.LogStr);
                }

            }
            catch (Exception e)
            {
                Console.WriteLine("Failed:" + msg_str);
                //Console.WriteLine(e.ToString());
            }
        }

        static void Main(string[] args)
        {

            Thread t = new Thread(Start);

            t.Start();
            ConsoleKeyInfo inputKey;

            while (isRun)
            {
                Console.WriteLine("after start, wait for user input:");
                inputKey = Console.ReadKey(true);
                switch (inputKey.Key)
                {
                    case ConsoleKey.Q:
                        {
                            isRun = false;
                            t.Join();
                            break;
                        }
                }
            }
        }
    }
}
