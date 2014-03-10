namespace OOP_Project
{
    partial class Magazin
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

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.panel1 = new System.Windows.Forms.Panel();
            this.buton_prototip_zi = new System.Windows.Forms.Button();
            this.buton_adauga_zi_noua = new System.Windows.Forms.Button();
            this.panel2 = new System.Windows.Forms.Panel();
            this.label_nr_profit = new System.Windows.Forms.Label();
            this.label_nr_cost = new System.Windows.Forms.Label();
            this.label_nr_pret = new System.Windows.Forms.Label();
            this.label_nr_cantitate = new System.Windows.Forms.Label();
            this.label_prototip_aliment = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.label_profit_total = new System.Windows.Forms.Label();
            this.label_cost_total = new System.Windows.Forms.Label();
            this.label_pret_total = new System.Windows.Forms.Label();
            this.label_canitate_totala = new System.Windows.Forms.Label();
            this.panel1.SuspendLayout();
            this.panel2.SuspendLayout();
            this.SuspendLayout();
            // 
            // panel1
            // 
            this.panel1.AutoScroll = true;
            this.panel1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panel1.Controls.Add(this.buton_prototip_zi);
            this.panel1.Location = new System.Drawing.Point(12, 76);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(451, 421);
            this.panel1.TabIndex = 0;
            // 
            // buton_prototip_zi
            // 
            this.buton_prototip_zi.BackColor = System.Drawing.Color.LightGreen;
            this.buton_prototip_zi.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.buton_prototip_zi.Font = new System.Drawing.Font("Times New Roman", 27.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buton_prototip_zi.Location = new System.Drawing.Point(58, 33);
            this.buton_prototip_zi.Name = "buton_prototip_zi";
            this.buton_prototip_zi.Size = new System.Drawing.Size(331, 51);
            this.buton_prototip_zi.TabIndex = 0;
            this.buton_prototip_zi.Text = "Ziua 1";
            this.buton_prototip_zi.UseVisualStyleBackColor = false;
            this.buton_prototip_zi.Visible = false;
            // 
            // buton_adauga_zi_noua
            // 
            this.buton_adauga_zi_noua.AutoSize = true;
            this.buton_adauga_zi_noua.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.buton_adauga_zi_noua.BackColor = System.Drawing.Color.LightSteelBlue;
            this.buton_adauga_zi_noua.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.buton_adauga_zi_noua.Font = new System.Drawing.Font("Times New Roman", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buton_adauga_zi_noua.Location = new System.Drawing.Point(12, 12);
            this.buton_adauga_zi_noua.Name = "buton_adauga_zi_noua";
            this.buton_adauga_zi_noua.Size = new System.Drawing.Size(126, 31);
            this.buton_adauga_zi_noua.TabIndex = 1;
            this.buton_adauga_zi_noua.Text = "Adauga o zi noua";
            this.buton_adauga_zi_noua.UseVisualStyleBackColor = false;
            this.buton_adauga_zi_noua.Click += new System.EventHandler(this.buton_adauga_zi_noua_Click);
            // 
            // panel2
            // 
            this.panel2.AutoScroll = true;
            this.panel2.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panel2.Controls.Add(this.label_nr_profit);
            this.panel2.Controls.Add(this.label_nr_cost);
            this.panel2.Controls.Add(this.label_nr_pret);
            this.panel2.Controls.Add(this.label_nr_cantitate);
            this.panel2.Controls.Add(this.label_prototip_aliment);
            this.panel2.Controls.Add(this.label1);
            this.panel2.Controls.Add(this.label_profit_total);
            this.panel2.Controls.Add(this.label_cost_total);
            this.panel2.Controls.Add(this.label_pret_total);
            this.panel2.Controls.Add(this.label_canitate_totala);
            this.panel2.Location = new System.Drawing.Point(469, 76);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(504, 421);
            this.panel2.TabIndex = 2;
            // 
            // label_nr_profit
            // 
            this.label_nr_profit.AutoSize = true;
            this.label_nr_profit.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label_nr_profit.Location = new System.Drawing.Point(252, 74);
            this.label_nr_profit.Name = "label_nr_profit";
            this.label_nr_profit.Size = new System.Drawing.Size(18, 20);
            this.label_nr_profit.TabIndex = 14;
            this.label_nr_profit.Text = "0";
            // 
            // label_nr_cost
            // 
            this.label_nr_cost.AutoSize = true;
            this.label_nr_cost.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label_nr_cost.Location = new System.Drawing.Point(247, 54);
            this.label_nr_cost.Name = "label_nr_cost";
            this.label_nr_cost.Size = new System.Drawing.Size(18, 20);
            this.label_nr_cost.TabIndex = 13;
            this.label_nr_cost.Text = "0";
            // 
            // label_nr_pret
            // 
            this.label_nr_pret.AutoSize = true;
            this.label_nr_pret.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label_nr_pret.Location = new System.Drawing.Point(245, 33);
            this.label_nr_pret.Name = "label_nr_pret";
            this.label_nr_pret.Size = new System.Drawing.Size(18, 20);
            this.label_nr_pret.TabIndex = 12;
            this.label_nr_pret.Text = "0";
            // 
            // label_nr_cantitate
            // 
            this.label_nr_cantitate.AutoSize = true;
            this.label_nr_cantitate.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label_nr_cantitate.Location = new System.Drawing.Point(231, 11);
            this.label_nr_cantitate.Name = "label_nr_cantitate";
            this.label_nr_cantitate.Size = new System.Drawing.Size(18, 20);
            this.label_nr_cantitate.TabIndex = 11;
            this.label_nr_cantitate.Text = "0";
            // 
            // label_prototip_aliment
            // 
            this.label_prototip_aliment.AutoSize = true;
            this.label_prototip_aliment.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label_prototip_aliment.Location = new System.Drawing.Point(3, 148);
            this.label_prototip_aliment.Name = "label_prototip_aliment";
            this.label_prototip_aliment.Size = new System.Drawing.Size(73, 20);
            this.label_prototip_aliment.TabIndex = 10;
            this.label_prototip_aliment.Text = "aliment 1";
            this.label_prototip_aliment.Visible = false;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(3, 119);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(146, 20);
            this.label1.TabIndex = 9;
            this.label1.Text = "Alimentele din stoc:";
            // 
            // label_profit_total
            // 
            this.label_profit_total.AutoSize = true;
            this.label_profit_total.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label_profit_total.Location = new System.Drawing.Point(3, 74);
            this.label_profit_total.Name = "label_profit_total";
            this.label_profit_total.Size = new System.Drawing.Size(253, 20);
            this.label_profit_total.TabIndex = 8;
            this.label_profit_total.Text = "Profitul total al produselor vandute:";
            // 
            // label_cost_total
            // 
            this.label_cost_total.AutoSize = true;
            this.label_cost_total.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label_cost_total.Location = new System.Drawing.Point(3, 54);
            this.label_cost_total.Name = "label_cost_total";
            this.label_cost_total.Size = new System.Drawing.Size(249, 20);
            this.label_cost_total.TabIndex = 7;
            this.label_cost_total.Text = "Costul total al produselor vandute:";
            // 
            // label_pret_total
            // 
            this.label_pret_total.AutoSize = true;
            this.label_pret_total.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label_pret_total.Location = new System.Drawing.Point(3, 33);
            this.label_pret_total.Name = "label_pret_total";
            this.label_pret_total.Size = new System.Drawing.Size(245, 20);
            this.label_pret_total.TabIndex = 6;
            this.label_pret_total.Text = "Pretul total al produselor vandute:";
            // 
            // label_canitate_totala
            // 
            this.label_canitate_totala.AutoSize = true;
            this.label_canitate_totala.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label_canitate_totala.Location = new System.Drawing.Point(3, 11);
            this.label_canitate_totala.Name = "label_canitate_totala";
            this.label_canitate_totala.Size = new System.Drawing.Size(232, 20);
            this.label_canitate_totala.TabIndex = 5;
            this.label_canitate_totala.Text = "Cantitatea de produse vandute:";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoScroll = true;
            this.BackColor = System.Drawing.Color.White;
            this.ClientSize = new System.Drawing.Size(985, 509);
            this.Controls.Add(this.panel2);
            this.Controls.Add(this.buton_adauga_zi_noua);
            this.Controls.Add(this.panel1);
            this.Name = "Form1";
            this.Text = "Magazin";
            this.panel1.ResumeLayout(false);
            this.panel2.ResumeLayout(false);
            this.panel2.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        public System.Windows.Forms.Panel panel1;
        public System.Windows.Forms.Button buton_prototip_zi;
        public System.Windows.Forms.Button buton_adauga_zi_noua;
        public System.Windows.Forms.Panel panel2;
        public System.Windows.Forms.Label label_profit_total;
        public System.Windows.Forms.Label label_cost_total;
        public System.Windows.Forms.Label label_pret_total;
        public System.Windows.Forms.Label label_canitate_totala;
        public System.Windows.Forms.Label label_prototip_aliment;
        public System.Windows.Forms.Label label1;
        public System.Windows.Forms.Label label_nr_profit;
        public System.Windows.Forms.Label label_nr_cost;
        public System.Windows.Forms.Label label_nr_pret;
        public System.Windows.Forms.Label label_nr_cantitate;
    }
}

