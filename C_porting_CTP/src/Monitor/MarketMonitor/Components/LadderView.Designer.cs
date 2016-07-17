namespace MarketMonitor.Components
{
    partial class LadderView
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
            if (disposing)
            {

            }

            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.tlPanel = new System.Windows.Forms.TableLayoutPanel();
            this.closeBtn = new System.Windows.Forms.Button();
            this.ladder = new System.Windows.Forms.DataGridView();
            this.SymbolLabel = new System.Windows.Forms.Label();
            this.Date_Time = new System.Windows.Forms.Label();
            this.BuyOrder = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.bidVolume = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.lastPrice = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.askVolume = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.SellOrder = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Volume = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.tlPanel.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.ladder)).BeginInit();
            this.SuspendLayout();
            // 
            // tlPanel
            // 
            this.tlPanel.BackColor = System.Drawing.Color.DimGray;
            this.tlPanel.ColumnCount = 3;
            this.tlPanel.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tlPanel.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Absolute, 150F));
            this.tlPanel.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tlPanel.Controls.Add(this.closeBtn, 1, 2);
            this.tlPanel.Controls.Add(this.ladder, 0, 1);
            this.tlPanel.Controls.Add(this.SymbolLabel, 0, 0);
            this.tlPanel.Controls.Add(this.Date_Time, 2, 0);
            this.tlPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tlPanel.Location = new System.Drawing.Point(0, 0);
            this.tlPanel.Name = "tlPanel";
            this.tlPanel.RowCount = 3;
            this.tlPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 30F));
            this.tlPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.tlPanel.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 30F));
            this.tlPanel.Size = new System.Drawing.Size(651, 117);
            this.tlPanel.TabIndex = 0;
            this.tlPanel.MouseDown += new System.Windows.Forms.MouseEventHandler(this.ladder_MouseDown);
            this.tlPanel.MouseMove += new System.Windows.Forms.MouseEventHandler(this.ladder_MouseMove);
            this.tlPanel.MouseUp += new System.Windows.Forms.MouseEventHandler(this.ladder_MouseUp);
            // 
            // closeBtn
            // 
            this.closeBtn.Dock = System.Windows.Forms.DockStyle.Fill;
            this.closeBtn.Location = new System.Drawing.Point(253, 90);
            this.closeBtn.Name = "closeBtn";
            this.closeBtn.Size = new System.Drawing.Size(144, 24);
            this.closeBtn.TabIndex = 5;
            this.closeBtn.Text = "关闭";
            this.closeBtn.UseVisualStyleBackColor = true;
            this.closeBtn.Click += new System.EventHandler(this.closeBtn_Click);
            // 
            // ladder
            // 
            this.ladder.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.ladder.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.BuyOrder,
            this.bidVolume,
            this.lastPrice,
            this.askVolume,
            this.SellOrder,
            this.Volume});
            this.tlPanel.SetColumnSpan(this.ladder, 3);
            this.ladder.Dock = System.Windows.Forms.DockStyle.Fill;
            this.ladder.Location = new System.Drawing.Point(3, 33);
            this.ladder.Name = "ladder";
            this.ladder.RowTemplate.Height = 23;
            this.ladder.Size = new System.Drawing.Size(645, 51);
            this.ladder.TabIndex = 3;
            // 
            // SymbolLabel
            // 
            this.SymbolLabel.AutoSize = true;
            this.SymbolLabel.BackColor = System.Drawing.Color.Transparent;
            this.SymbolLabel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.SymbolLabel.Font = new System.Drawing.Font("SimSun", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.SymbolLabel.ForeColor = System.Drawing.Color.Yellow;
            this.SymbolLabel.Location = new System.Drawing.Point(3, 0);
            this.SymbolLabel.Name = "SymbolLabel";
            this.SymbolLabel.Size = new System.Drawing.Size(244, 30);
            this.SymbolLabel.TabIndex = 6;
            // 
            // Date_Time
            // 
            this.Date_Time.AutoSize = true;
            this.Date_Time.BackColor = System.Drawing.Color.Transparent;
            this.Date_Time.Dock = System.Windows.Forms.DockStyle.Fill;
            this.Date_Time.ForeColor = System.Drawing.Color.Yellow;
            this.Date_Time.Location = new System.Drawing.Point(403, 0);
            this.Date_Time.Name = "Date_Time";
            this.Date_Time.Size = new System.Drawing.Size(245, 30);
            this.Date_Time.TabIndex = 7;
            // 
            // BuyOrder
            // 
            this.BuyOrder.HeaderText = "多单";
            this.BuyOrder.Name = "BuyOrder";
            this.BuyOrder.ReadOnly = true;
            // 
            // bidVolume
            // 
            this.bidVolume.HeaderText = "买单量";
            this.bidVolume.Name = "bidVolume";
            this.bidVolume.ReadOnly = true;
            // 
            // lastPrice
            // 
            this.lastPrice.HeaderText = "价格";
            this.lastPrice.Name = "lastPrice";
            this.lastPrice.ReadOnly = true;
            // 
            // askVolume
            // 
            this.askVolume.HeaderText = "卖单量";
            this.askVolume.Name = "askVolume";
            this.askVolume.ReadOnly = true;
            // 
            // SellOrder
            // 
            this.SellOrder.HeaderText = "空单";
            this.SellOrder.Name = "SellOrder";
            this.SellOrder.ReadOnly = true;
            // 
            // Volume
            // 
            this.Volume.HeaderText = "现手";
            this.Volume.Name = "Volume";
            this.Volume.ReadOnly = true;
            // 
            // LadderView
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(651, 117);
            this.Controls.Add(this.tlPanel);
            this.Name = "LadderView";
            this.Text = "市场深度报价";
            this.Load += new System.EventHandler(this.LadderView_Load);
            this.tlPanel.ResumeLayout(false);
            this.tlPanel.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.ladder)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TableLayoutPanel tlPanel;
        private System.Windows.Forms.DataGridView ladder;
        private System.Windows.Forms.Button closeBtn;
        private System.Windows.Forms.Label SymbolLabel;
        private System.Windows.Forms.Label Date_Time;
        private System.Windows.Forms.DataGridViewTextBoxColumn BuyOrder;
        private System.Windows.Forms.DataGridViewTextBoxColumn bidVolume;
        private System.Windows.Forms.DataGridViewTextBoxColumn lastPrice;
        private System.Windows.Forms.DataGridViewTextBoxColumn askVolume;
        private System.Windows.Forms.DataGridViewTextBoxColumn SellOrder;
        private System.Windows.Forms.DataGridViewTextBoxColumn Volume;


    }
}