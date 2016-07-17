using System;
using System.Collections;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using Newtonsoft.Json;

namespace MarketMonitor
{
    class Utils<T>
    {
        public static void GetConfig(string con_file_path, out T cfm)
        {
            try
            {
                using (StreamReader sr = new StreamReader(con_file_path))
                {
                    string content = sr.ReadToEnd();

                    cfm = JsonConvert.DeserializeObject<T>(content);
                    /*
                    JsonSerializer serializer = new JsonSerializer();
                    serializer.NullValueHandling = NullValueHandling.Ignore;

                    JsonReader reader = new JsonTextReader(sr);
                    cfm = serializer.Deserialize<T>(reader);
                     * */
                }
            }
            catch (Exception ex)
            {
                cfm = default(T);
                ex.Message.ToString();
            }
        }
    }

    class ConfigFile
    {

        public static ConfigFile cfm = null;

        public string ip_addr = "";
    }
    
    class Instrument
    {
        public string Symbol = "";
        public int VolumeMultiple = -1;
        public double PriceTick = -1;
    }

    class InstrumentList
    {

        public static ConcurrentDictionary<string, Instrument> dict = new ConcurrentDictionary<string, Instrument>();

        public static void GenDict(List<Instrument> lst)
        {
            foreach(Instrument ins in lst)
            {
                dict.GetOrAdd(ins.Symbol, ins);
            }
        }

        public List<Instrument> instruments = new List<Instrument>();
    }
}
