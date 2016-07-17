using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace MarketMonitor.Components
{
    public partial class LadderView : Form
    {

        private delegate void updateUI(MarketDataMsg md);
        public void doUpdateUI(MarketDataMsg md)
        {
            Date_Time.Text = String.Format("{0} {1}.{2}", md.TradingDay,
                    md.UpdateTime, md.UpdateMillisec);

            ResetVal();

            int row_num = CalcRowNum(md.UpperLimitPrice, md.LastPrice, PriceTick);

            int max_row = ladder.RowCount - 1;

            if (row_num < 0 || row_num > max_row)
            {
                return;
            }

            int show_line = row_num - line_num / 2;

            ladder[5, row_num].Value = md.Volume;
            ladder[2, row_num].Style.ForeColor = Color.Black;
            ladder[2, row_num].Style.BackColor = Color.LightBlue;

            row_num = CalcRowNum(md.UpperLimitPrice, md.BidPrice, PriceTick);

            if (row_num < 0 || row_num > max_row)
            {
                return;
            }

            ladder[1, row_num].Value = md.BidVolume;

            row_num = CalcRowNum(md.UpperLimitPrice, md.AskPrice, PriceTick);

            if (row_num < 0 || row_num > max_row)
            {
                return;
            }
            ladder[3, row_num].Value = md.AskVolume;

            show_line = show_line > max_row ? max_row : show_line;

            if (needScroll)
            {
                ladder.FirstDisplayedScrollingRowIndex = show_line;
                needScroll = false;
            }
        }

        public LadderView()
        {
            InitializeComponent();
        }

        public void ShowMdData(object sender, MdEventArgs e)
        {

            MarketDataMsg md = e.msg;
            if (!md.Symbol.Equals(Symbol))
            {
                return;
            }

            if (md != null)
            {
                if (!IsDisposed && IsHandleCreated)
                {
                    BeginInvoke(new updateUI(doUpdateUI), md);
                }
            }
        }

        private int CalcRowNum(double _d1, double _d2, double price_tick)
        {
            int multi = 100;
            return ((int)(multi * _d1) - (int)(multi * _d2)) / (int)(multi * price_tick);
        }

        private int line_num = -1;

        public void InitLadder(MdEventArgs md_arg)
        {
            MarketDataMsg md = md_arg.msg;

            if (ladder.RowCount == 1)
            {
                int max_num = CalcRowNum(md.UpperLimitPrice, md.LowerLimitPrice, PriceTick);

                int row_num = 0;
                while (row_num < max_num)
                {
                    row_num = ladder.Rows.Add();
                    ladder.Rows[row_num].Cells[2].Value = md.UpperLimitPrice - row_num * PriceTick;
                }

                Top = 0;
                Height = Screen.PrimaryScreen.Bounds.Height - 100;
                line_num = (Height - 60) / ladder.ColumnHeadersHeight - 3;

                SymbolLabel.Text = md.Symbol;

            }

        }

        public string Symbol { get; set; }

        public double PriceTick { get; set; }

        Point mouseOff;//鼠标移动位置变量

        bool leftFlag;//标签是否为左键
        private bool needScroll = true;

        private void ResetVal()
        {
            for (int i = 0; i < ladder.Rows.Count; i++)
            {
                ladder[1, i].Value = "";
                ladder[2, i].Style.ForeColor = Color.Yellow;
                ladder[2, i].Style.BackColor = Color.Blue;
                ladder[3, i].Value = "";
                ladder[5, i].Value = "";
            }
        }

        private void ResetColor()
        {
            for (int i = 0; i < ladder.Columns.Count; i++)
            {
                ladder.Columns[i].DefaultCellStyle.ForeColor = Color.Yellow;
                ladder.Columns[i].DefaultCellStyle.BackColor = Color.Black;
            }

            int buy_col = 1;
            ladder.Columns[buy_col].DefaultCellStyle.ForeColor = Color.Yellow;
            ladder.Columns[buy_col].DefaultCellStyle.BackColor = Color.Red;
            ladder.Columns[buy_col + 1].DefaultCellStyle.ForeColor = Color.Yellow;
            ladder.Columns[buy_col + 1].DefaultCellStyle.BackColor = Color.Blue;
            ladder.Columns[buy_col + 2].DefaultCellStyle.ForeColor = Color.Yellow;
            ladder.Columns[buy_col + 2].DefaultCellStyle.BackColor = Color.Green;
        }

        private void LadderView_Load(object sender, EventArgs e)
        {
            this.FormBorderStyle = FormBorderStyle.None;

            tlPanel.SetColumnSpan(ladder, 3);

            ladder.AllowUserToAddRows = false;
            ladder.RowHeadersVisible = false;

            ladder.AllowUserToResizeColumns = false;
            ladder.AllowUserToResizeRows = false;

            int w = 0;
            int vol_w = 50;
            ladder.Columns[1].Width = vol_w;
            ladder.Columns[3].Width = vol_w;
            ladder.Columns[5].Width = vol_w;

            for (int i = 0; i < ladder.Columns.Count; i++)
            {
                ladder.Columns[i].SortMode = DataGridViewColumnSortMode.NotSortable;
                w += ladder.Columns[i].Width;
            }

            w += ladder.VerticalScrollingOffset;
            w += SystemInformation.VerticalScrollBarWidth;
            w += 20;

            Width = w;

            ResetColor();
        }

        private void ladder_MouseDown(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)//如果按下的是鼠标左键
            {
                mouseOff = new Point(-e.X, -e.Y); //得到变量的值
                leftFlag = true; //点击左键按下时标注为true;
            }
        }

        private void ladder_MouseMove(object sender, MouseEventArgs e)
        {
            if (leftFlag)//如果鼠标左键是按下的状态
            {
                Point mouseSet = Control.MousePosition;
                mouseSet.Offset(mouseOff.X, mouseOff.Y); //设置移动后的位置
                Location = mouseSet;
            }
        }

        private void ladder_MouseUp(object sender, MouseEventArgs e)
        {
            if (leftFlag)//如果鼠标左键是松开的状态
            {
                leftFlag = false;//释放鼠标后标注为false;
            }
        }

        private void closeBtn_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
