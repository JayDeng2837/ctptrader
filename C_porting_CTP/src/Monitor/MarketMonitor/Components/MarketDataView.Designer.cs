namespace MarketMonitor.Components
{
    partial class MarketDataView
    {
        /// <summary> 
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary> 
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }

            base.Dispose(disposing);
        }

        #region Component Designer generated code

        /// <summary> 
        /// Required method for Designer support - do not modify 
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.marketdataGridView = new System.Windows.Forms.DataGridView();
            this.Symbol = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.DateTime = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.LastPrice = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Volume = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.accVol = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.AskPrice = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.AskVolume = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.BidPrice = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.BidVolume = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.deltaOI = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.OpenInterest = new System.Windows.Forms.DataGridViewTextBoxColumn();
            ((System.ComponentModel.ISupportInitialize)(this.marketdataGridView)).BeginInit();
            this.SuspendLayout();
            // 
            // marketdataGridView
            // 
            this.marketdataGridView.AllowUserToAddRows = false;
            this.marketdataGridView.AllowUserToDeleteRows = false;
            this.marketdataGridView.AllowUserToResizeColumns = false;
            this.marketdataGridView.AllowUserToResizeRows = false;
            this.marketdataGridView.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.marketdataGridView.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.Symbol,
            this.DateTime,
            this.LastPrice,
            this.Volume,
            this.accVol,
            this.AskPrice,
            this.AskVolume,
            this.BidPrice,
            this.BidVolume,
            this.deltaOI,
            this.OpenInterest});
            this.marketdataGridView.Dock = System.Windows.Forms.DockStyle.Fill;
            this.marketdataGridView.EditMode = System.Windows.Forms.DataGridViewEditMode.EditProgrammatically;
            this.marketdataGridView.Location = new System.Drawing.Point(0, 0);
            this.marketdataGridView.MultiSelect = false;
            this.marketdataGridView.Name = "marketdataGridView";
            this.marketdataGridView.ReadOnly = true;
            this.marketdataGridView.RowTemplate.Height = 23;
            this.marketdataGridView.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.marketdataGridView.Size = new System.Drawing.Size(990, 100);
            this.marketdataGridView.TabIndex = 0;
            this.marketdataGridView.VirtualMode = true;
            this.marketdataGridView.CellMouseDoubleClick += new System.Windows.Forms.DataGridViewCellMouseEventHandler(this.marketdataGridView_CellMouseDoubleClick);
            this.marketdataGridView.CellValueNeeded += new System.Windows.Forms.DataGridViewCellValueEventHandler(this.marketdataGridView_CellValueNeeded);
            this.marketdataGridView.ColumnHeaderMouseClick += new System.Windows.Forms.DataGridViewCellMouseEventHandler(this.marketdataGridView_ColumnHeaderMouseClick);
            // 
            // Symbol
            // 
            this.Symbol.HeaderText = "合约号";
            this.Symbol.Name = "Symbol";
            this.Symbol.ReadOnly = true;
            this.Symbol.Width = 120;
            // 
            // DateTime
            // 
            this.DateTime.HeaderText = "时间";
            this.DateTime.Name = "DateTime";
            this.DateTime.ReadOnly = true;
            this.DateTime.Width = 150;
            // 
            // LastPrice
            // 
            this.LastPrice.HeaderText = "最新价";
            this.LastPrice.Name = "LastPrice";
            this.LastPrice.ReadOnly = true;
            this.LastPrice.Width = 80;
            // 
            // Volume
            // 
            this.Volume.HeaderText = "成交量";
            this.Volume.Name = "Volume";
            this.Volume.ReadOnly = true;
            this.Volume.Width = 70;
            // 
            // accVol
            // 
            this.accVol.HeaderText = "总成交量";
            this.accVol.Name = "accVol";
            this.accVol.ReadOnly = true;
            this.accVol.Width = 80;
            // 
            // AskPrice
            // 
            this.AskPrice.HeaderText = "卖一价";
            this.AskPrice.Name = "AskPrice";
            this.AskPrice.ReadOnly = true;
            this.AskPrice.Width = 80;
            // 
            // AskVolume
            // 
            this.AskVolume.HeaderText = "卖量";
            this.AskVolume.Name = "AskVolume";
            this.AskVolume.ReadOnly = true;
            this.AskVolume.Width = 60;
            // 
            // BidPrice
            // 
            this.BidPrice.HeaderText = "买一价";
            this.BidPrice.Name = "BidPrice";
            this.BidPrice.ReadOnly = true;
            this.BidPrice.Width = 80;
            // 
            // BidVolume
            // 
            this.BidVolume.HeaderText = "买量";
            this.BidVolume.Name = "BidVolume";
            this.BidVolume.ReadOnly = true;
            this.BidVolume.Width = 60;
            // 
            // deltaOI
            // 
            this.deltaOI.HeaderText = "仓差";
            this.deltaOI.Name = "deltaOI";
            this.deltaOI.ReadOnly = true;
            this.deltaOI.Width = 60;
            // 
            // OpenInterest
            // 
            this.OpenInterest.HeaderText = "持仓量";
            this.OpenInterest.Name = "OpenInterest";
            this.OpenInterest.ReadOnly = true;
            this.OpenInterest.Width = 80;
            // 
            // MarketDataView
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(990, 100);
            this.Controls.Add(this.marketdataGridView);
            this.Font = new System.Drawing.Font("SimSun", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.Name = "MarketDataView";
            this.Text = "合约列表";
            this.Load += new System.EventHandler(this.MarketDataView_Load);
            ((System.ComponentModel.ISupportInitialize)(this.marketdataGridView)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.DataGridView marketdataGridView;
        private System.Windows.Forms.DataGridViewTextBoxColumn Symbol;
        private System.Windows.Forms.DataGridViewTextBoxColumn DateTime;
        private System.Windows.Forms.DataGridViewTextBoxColumn LastPrice;
        private System.Windows.Forms.DataGridViewTextBoxColumn Volume;
        private System.Windows.Forms.DataGridViewTextBoxColumn accVol;
        private System.Windows.Forms.DataGridViewTextBoxColumn AskPrice;
        private System.Windows.Forms.DataGridViewTextBoxColumn AskVolume;
        private System.Windows.Forms.DataGridViewTextBoxColumn BidPrice;
        private System.Windows.Forms.DataGridViewTextBoxColumn BidVolume;
        private System.Windows.Forms.DataGridViewTextBoxColumn deltaOI;
        private System.Windows.Forms.DataGridViewTextBoxColumn OpenInterest;
    }
}
