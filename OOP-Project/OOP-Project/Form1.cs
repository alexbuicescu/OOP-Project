﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace OOP_Project
{
    public partial class Form1 : Form
    {
        public List<Label> listaProduseLabel = new List<Label>();
        public List<Button> listaButoane = new List<Button>();
        public Dictionary<Button, String> hashDeButoane = new Dictionary<Button, String>();

        int nr_of_days = 0;

        double cantitate_totala = 0, pret_total = 0, cost_total = 0, profit_total = 0;

        Button last_clicked_button = null;

        public Form1()
        {
            InitializeComponent();
            check_for_how_many_days_are();
            addListOfButtons();
        }

        public void check_for_how_many_days_are()
        {
            string text = System.IO.File.ReadAllText(@"Baza de date/numar de zile.txt");

            try
            {
                nr_of_days = int.Parse(text);
            }
            catch(Exception ex)
            {
                nr_of_days = 0;
            }
        }

        public void addListOfButtons()
        {
            int currentPositionX = buton_prototip_zi.Location.X, currentPositionY = buton_prototip_zi.Location.Y;
            int buttonWidth = buton_prototip_zi.Size.Width, buttonHeight = buton_prototip_zi.Size.Height;
            int theGapBetweenButtons = 15;//15 pixels

            for (int i = 0; i < nr_of_days; i++)
            {
                Button buton = new Button();//null
                createButton(currentPositionX, currentPositionY, buttonWidth, buttonHeight, "Ziua " + (i + 1).ToString(), ref buton);

                listaButoane.Add(buton);
                hashDeButoane.Add(buton, buton.Text);

                //MessageBox.Show(buton.Text);
                //Debug.WriteLine(buton.Text);

                currentPositionY += buttonHeight + theGapBetweenButtons;
            }
        }

        public void createButton(int xPosition, int yPosition, int widthSize, int heightSize, String text, ref Button buton)
        {
            //buton = new Button();
            buton.BackColor = System.Drawing.Color.LightGreen;
            buton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            buton.Font = new System.Drawing.Font("Times New Roman", 27.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            buton.Location = new System.Drawing.Point(xPosition, yPosition);
            buton.Name = "button1"; ///kind of random, doesn't mater
            buton.Size = new System.Drawing.Size(widthSize, heightSize);
            buton.TabIndex = 0; ///if you press TAB it will jump to the next button
            buton.Text = text;
            buton.UseVisualStyleBackColor = true; ///kind of random, doesn't matter

            buton.Click += new EventHandler(clickAction);

            panel1.Controls.Add(buton); ///most important, it adds the button to the form
        }

        private void clickAction(object sender, EventArgs e)
        {
            if (last_clicked_button != null)
            {
                last_clicked_button.BackColor = System.Drawing.Color.LightGreen;

                for (int i = 0; i < listaProduseLabel.Count; i++)
                {
                    panel2.Controls.Remove(listaProduseLabel[i]);
                }
                listaProduseLabel.Clear();
            }
            ((Button)sender).BackColor = System.Drawing.Color.LightYellow;
            last_clicked_button = (Button)sender;

            string[] lines = System.IO.File.ReadAllLines(@"Baza de date/" + ((Button)sender).Text + "/db.txt");

            string[] vals_line_1 = lines[0].Split(' ');
            cantitate_totala = double.Parse(vals_line_1[0]);
            pret_total = double.Parse(vals_line_1[1]);
            cost_total = double.Parse(vals_line_1[2]);
            profit_total = double.Parse(vals_line_1[3]);

            label_nr_cantitate.Text = cantitate_totala.ToString();
            label_nr_pret.Text = pret_total.ToString() + " de LEI";
            label_nr_cost.Text = cost_total.ToString() + " de LEI";
            label_nr_profit.Text = profit_total.ToString() + " de LEI";

            addListOfLabels(lines);

            //MessageBox.Show(hashDeButoane[(Button)sender]); ///object este echivalentul lui void *el din C, deci deaia trebuie sa pun (Button)sender, ca sa ii spun ca sender este defapt un buton
            ///in locul lui (Button) puteam sa pun (TextBox) sau orice altceva
        }

        private void buton_adauga_zi_noua_Click(object sender, EventArgs e)
        {
            Zi_noua _val = new Zi_noua(this);
            _val.Show();
        }

        public void addListOfLabels(string[] labelTexturi)
        {
            int currentPositionX = label_prototip_aliment.Location.X, currentPositionY = label_prototip_aliment.Location.Y;
            int buttonWidth = label_prototip_aliment.Size.Width, buttonHeight = label_prototip_aliment.Size.Height;
            int theGapBetweenButtons = 15;//15 pixels

            for (int i = 1; i < labelTexturi.Length; i++)
            {
                Label buton = new Label();//null
                createLabel(currentPositionX, currentPositionY, buttonWidth, buttonHeight, labelTexturi[i], ref buton);

                listaProduseLabel.Add(buton);

                currentPositionY += buttonHeight + theGapBetweenButtons;
            }
        }

        public void createLabel(int xPosition, int yPosition, int widthSize, int heightSize, String text, ref Label buton)
        {
            //buton = new Button();
            buton.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            buton.Location = new System.Drawing.Point(xPosition, yPosition);
            buton.Name = "button1"; ///kind of random, doesn't mater
            buton.AutoSize = true;
            //buton.Size = new System.Drawing.Size(widthSize, heightSize);
            buton.TabIndex = 0; ///if you press TAB it will jump to the next button
            buton.Text = text;
            
            panel2.Controls.Add(buton); ///most important, it adds the button to the form
        }

        private void button1_Click(object sender, EventArgs e)
        {
            MessageBox.Show("asdasda");
        }

    }
}
