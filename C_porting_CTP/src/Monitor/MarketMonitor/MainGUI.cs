using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using WinFormsUI.Docking;
using MarketMonitor.Components;

using System.Threading;

using NetMQ;

namespace MarketMonitor
{

    public partial class MainGUI : Form
    {
        public MainGUI()
        {
            InitializeComponent();
        }

        protected override void OnFormClosing(FormClosingEventArgs e)
        {
            isRun = false;

            if (t != null)
            {
                t.Join();
                t = null;
            }
        }

        private void MainGUI_Load(object sender, EventArgs e)
        {

            Utils<ConfigFile>.GetConfig("config.json", out ConfigFile.cfm);

            InstrumentList lst = null;

            Utils<InstrumentList>.GetConfig("instrument.txt", out lst);

            if (lst == null)
            {
                Application.Exit();
                return;
            }

            InstrumentList.GenDict(lst.instruments);

            //------------------------

            dataView = new MarketDataView();

            dataView.Show(dockPanel);

            Width = 900;

            t = new Thread(subcribeData);

            t.Start();

        }

        public delegate void GetDataHandler(Byte[] message);

        public static event GetDataHandler OnGetData;

        private bool isRun = true;

        private void subcribeData()
        {
            OnGetData += new GetDataHandler(dataView.ProcessData);
            long recv_timeout = TimeSpan.TicksPerSecond;
            using (var context = NetMQContext.Create())
            using (var subscriber = context.CreateSubscriberSocket())
            {
                subscriber.Connect(ConfigFile.cfm.ip_addr);
                subscriber.Subscribe("");
                while (isRun)
                {

                    try
                    {
                        NetMQMessage msg = subscriber.ReceiveMessage(new TimeSpan(recv_timeout));

                        if (null == msg)
                        {
                            throw new Exception("timeout");
                        }

                        if (msg.FrameCount < 2)
                        {
                            Console.WriteLine("got small package");
                        }

                        OnGetData(msg[msg.FrameCount - 1].Buffer);
                    }
                    catch (Exception ex)
                    {
                    }
                }
            }
        }

        private Thread t = null;

        private MarketDataView dataView = null;
    }
}
