using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Concurrent;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using System.Threading;

using WinFormsUI.Docking;

namespace MarketMonitor.Components
{

    public partial class MarketDataView : DockContent
    {
        public delegate void DispatchMdData(Object sender, MdEventArgs e);
        public event MarketDataView.DispatchMdData OnMdData;

        public MarketDataView()
        {
            InitializeComponent();
        }

        ~MarketDataView()
        {
        }

        private const int Symbol_Col = 0;
        private const int DateTime_Col = 1;
        private const int LastPrice_Col = 2;
        private const int Volume_Col = 3;
        private const int AccVolume_Col = 4;
        private const int AskPrice_Col = 5;
        private const int AskVol_Col = 6;
        private const int BidPrice_Col = 7;
        private const int BidVol_Col = 8;
        private const int DeltaOI_Col = 9;
        private const int OpenInterest_Col = 10;

        private const int time_interval = 200;

        private System.Windows.Forms.Timer timer = new System.Windows.Forms.Timer();

        private ConcurrentDictionary<string, int> info_table = new ConcurrentDictionary<string, int>();

        private List<string> symbol_lst = new List<string>();

        private ArrayList msg_list = new ArrayList();

        private AutoResetEvent eventHasDoneUpdateUI = new AutoResetEvent(false);

        public void ProcessData(Byte[] msg)
        {
            if (msg == null || msg.Length == 0)
            {
                Console.WriteLine("msg == null");
            }

            string msg_str = Encoding.ASCII.GetString(msg);

            try
            {
                MarketDataMsg md = MarketDataMsg.ParseFrom(msg);

                if (md != null)
                {
                    if (info_table.ContainsKey(md.Symbol))
                    {
                        int row_num = info_table[md.Symbol];
                        MdEventArgs md_ev = (MdEventArgs)msg_list[row_num];
                        md_ev.SetMsg(md);
                        msg_list[row_num] = md_ev;

                        if (OnMdData != null)
                            OnMdData(this, md_ev);
                    }
                }

            }
            catch (Exception e)
            {
                Console.WriteLine("Failed:" + msg_str);
            }
        }

#if LOCAL_DEMO
        private MarketDataMsg GetFakeOne()
        {
            MarketDataMsg.Builder builder = new MarketDataMsg.Builder();
            builder.SetSymbol("IF1505")
                .SetLastPrice(2400)
                .SetVolume(1001)
                .SetUpperLimitPrice(2450)
                .SetLowerLimitPrice(2300)
                .SetAskPrice(2401.4)
                .SetAskVolume(120)
                .SetBidPrice(2399.6)
                .SetBidVolume(30)
                .SetTradingDay("20150401")
                .SetUpdateTime("09:00:00")
                .SetUpdateMillisec(100);
            MarketDataMsg fake_md = builder.BuildPartial();

            return fake_md;
        }
#endif

        private void updateInfoList()
        {
            for (int i = 0; i < marketdataGridView.RowCount; i++)
            {
                string key = (string)marketdataGridView[0, i].Value;
                info_table[key] = i;
            }
        }

        private void MarketDataView_Load(object sender, EventArgs e)
        {

            foreach (KeyValuePair<string, Instrument> kvp in InstrumentList.dict)
            {
                int row_num = marketdataGridView.Rows.Add();
                info_table.GetOrAdd(kvp.Key, row_num);
                MarketDataMsg.Builder builder = new MarketDataMsg.Builder();
                builder.SetSymbol(kvp.Key);
                MdEventArgs md_ev = new MdEventArgs();
                md_ev.SetMsg(builder.BuildPartial(), true);
                msg_list.Add(md_ev);
            }

#if LOCAL_DEMO
            MarketDataMsg fake_md = GetFakeOne();
            msg_list[fake_md.Symbol] = fake_md;
            doUpdateUI(fake_md);
#endif

            timer.Interval = time_interval;
            timer.Tick += delegate(object o, EventArgs args)
            {
                marketdataGridView.Invalidate();
            };
            timer.Start();

        }

        private void marketdataGridView_CellValueNeeded(object sender, DataGridViewCellValueEventArgs e)
        {
            if (e.RowIndex < 0)
            {
                return;
            }

            MdEventArgs md = (MdEventArgs)msg_list[e.RowIndex];
            MarketDataMsg msg = md.msg;

            switch (e.ColumnIndex)
            {
                case Symbol_Col:
                    {
                        e.Value = msg.Symbol;
                        break;
                    }
                default:
                    {
                        switch (e.ColumnIndex)
                        {
                            case DateTime_Col:
                                {
                                    e.Value = msg.HasTradingDay ? string.Format("{0} {1}.{2}", msg.TradingDay,
                                        msg.UpdateTime, msg.UpdateMillisec) : string.Empty;
                                    break;
                                }
                            case LastPrice_Col:
                                {
                                    if (msg.HasLastPrice)
                                    {
                                        e.Value = msg.LastPrice;
                                    }
                                    break;
                                }
                            case Volume_Col:
                                {
                                    if (msg.HasVolume)
                                    {
                                        e.Value = msg.Volume;
                                    }
                                    break;
                                }
                            case AccVolume_Col:
                                {
                                    if (msg.HasAccVolume)
                                    {
                                        e.Value = msg.AccVolume;
                                    }
                                    break;
                                }
                            case AskPrice_Col:
                                {
                                    if (msg.HasAskPrice)
                                    {
                                        e.Value = msg.AskPrice;
                                    }
                                    break;
                                }
                            case AskVol_Col:
                                {
                                    if (msg.HasAskVolume)
                                    {
                                        e.Value = msg.AskVolume;
                                    }
                                    break;
                                }
                            case BidPrice_Col:
                                {
                                    if (msg.HasBidPrice)
                                    {
                                        e.Value = msg.BidPrice;
                                    }
                                    break;
                                }
                            case BidVol_Col:
                                {
                                    if (msg.HasBidVolume)
                                    {
                                        e.Value = msg.BidVolume;
                                    }
                                    break;
                                }
                            case DeltaOI_Col:
                                {
                                    if (msg.HasDeltaOpenInsterest)
                                    {
                                        e.Value = msg.DeltaOpenInsterest;
                                    }
                                    break;
                                }
                            case OpenInterest_Col:
                                {
                                    if (msg.HasOpenInterest)
                                    {
                                        e.Value = msg.OpenInterest;
                                    }
                                    break;
                                }
                        }
                        break;
                    }
            }
        }

        //  about sort
        private int iSortedColumnIdx = 0;
        private SortOrder iSortOrder = SortOrder.Ascending;

        private void marketdataGridView_ColumnHeaderMouseClick(object sender, DataGridViewCellMouseEventArgs e)
        {
            // Check which column is selected, otherwise set NewColumn to null.
            int newColumnIdx = e.ColumnIndex;
            DataGridViewColumn newColumn = null;
            if (newColumnIdx >= 0)
            {
                newColumn = marketdataGridView.Columns[newColumnIdx];
            }

            int oldColumnIdx = iSortedColumnIdx;
            ListSortDirection direction;

            // If oldColumn is null, then the DataGridView is not currently sorted.
            if (oldColumnIdx != -1)
            {
                // Sort the same column again, reversing the SortOrder.
                if (oldColumnIdx == newColumnIdx &&
                    iSortOrder == SortOrder.Ascending)
                {
                    direction = ListSortDirection.Descending;
                }
                else
                {
                    // Sort a new column and remove the old SortGlyph.
                    direction = ListSortDirection.Ascending;
                    DataGridViewColumn oldColumn = marketdataGridView.Columns[oldColumnIdx];
                    oldColumn.HeaderCell.SortGlyphDirection = SortOrder.None;
                }
            }
            else
            {
                direction = ListSortDirection.Ascending;
            }

            // If no column has been selected, display an error dialog  box.
            if (newColumn != null)
            {
                iSortOrder = direction == ListSortDirection.Ascending ? SortOrder.Ascending :
                             (direction == ListSortDirection.Descending ? SortOrder.Descending : SortOrder.None);

                iSortedColumnIdx = newColumnIdx;

                msg_list.Sort(new RowComparer(iSortOrder, iSortedColumnIdx));

                newColumn.HeaderCell.SortGlyphDirection =
                    direction == ListSortDirection.Ascending ?
                    SortOrder.Ascending : SortOrder.Descending;

                updateInfoList();

                marketdataGridView.Invalidate();
            }
        }

        private class RowComparer : System.Collections.IComparer
        {
            private int sortOrderModifier = 1;
            private int iSortedColumnIdx = 0;

            public RowComparer(SortOrder sortOrder, int iSortedColumnIdx)
            {
                if (sortOrder == SortOrder.Descending)
                {
                    sortOrderModifier = -1;
                }
                else if (sortOrder == SortOrder.Ascending)
                {
                    sortOrderModifier = 1;
                }

                this.iSortedColumnIdx = iSortedColumnIdx;
            }

            // 函数返回-1：表示a小于b，返回1：表示a大于b，返回0：表示a等于b
            public int Compare(object x, object y)
            {
                MdEventArgs a = (MdEventArgs)x;
                MdEventArgs b = (MdEventArgs)y;
                return sortOrderModifier * a.msg.Symbol.CompareTo(b.msg.Symbol);
            }
        }

        private void marketdataGridView_CellMouseDoubleClick(object sender, DataGridViewCellMouseEventArgs e)
        {
            if (e.RowIndex < 0)
            {
                return;
            }

            string symbol = Convert.ToString(marketdataGridView.Rows[e.RowIndex].Cells[0].Value);

            if (!symbol.Equals(string.Empty))
            {
                LadderView lv = new LadderView();

                lv.Symbol = symbol;
                lv.PriceTick = InstrumentList.dict[symbol].PriceTick;

                lv.InitLadder((MdEventArgs)msg_list[e.RowIndex]);

                lv.Show(this);

#if LOCAL_DEMO
            MarketDataMsg fake_md = GetFakeOne();
            lv.doUpdateUI(fake_md);
#endif

                OnMdData += new DispatchMdData(lv.ShowMdData);
            }

        }
    }

    public class MdEventArgs : EventArgs
    {
        public MarketDataMsg msg;

        public bool first_tick = true;
        public int ask_deal = 0;
        public int bid_deal = 0;
        
        internal void SetMsg(MarketDataMsg md, bool manual = false)
        {
            if (first_tick)
            {
                msg = md;
                if (!manual)
                {
                    first_tick = true;
                }
            }
            else
            {
                if (md.AvgPriceInTick > msg.AskPrice)
                {
                    ask_deal = md.Volume;
                    bid_deal = 0;
                }
                else if (md.AvgPriceInTick < msg.BidPrice)
                {
                    ask_deal = 0;
                    bid_deal = md.Volume;
                }
                else
                {
                    if (msg.AskPrice == msg.BidPrice)
                    {
                    }
                    else
                    {
                        ask_deal = (int)((md.Turnover - msg.BidPrice * md.Volume) / (msg.AskPrice - msg.BidPrice));
                        bid_deal = md.Volume - ask_deal;
                    }
                }
            }
        }
    }
}
