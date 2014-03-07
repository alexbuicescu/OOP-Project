using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Diagnostics;

namespace OOP_Project
{
    public partial class Zi_noua : Form
    {
        public List<TextBox> listaProduse = new List<TextBox>();
        public List<TextBox> listaCantitate = new List<TextBox>();
        Dictionary<TextBox, int> hashDeButoane = new Dictionary<TextBox, int>();
        int theGapBetweenButtons = 15;//15 pixels

        int lastY;

        int nr_of_aliments = 0;
        int nr_of_iterations = 0;

        Form1 initial_form;

        public Zi_noua(Form1 formul_initial)
        {
            InitializeComponent();

            initial_form = formul_initial;

            lastY = textBox1.Location.Y;
            
            addListOfButtons(textBox1, 1);
            addListOfButtons(textBox2, 2);

            ProcessStartInfo startInfo = new ProcessStartInfo();
            startInfo.FileName = "OOP-LAB.exe";
            Process.Start(startInfo);
        }


        public void addListOfButtons(TextBox _text_box, int i)
        {
            int currentPositionX = _text_box.Location.X;
            int buttonWidth = _text_box.Size.Width, buttonHeight = _text_box.Size.Height;

            //for (int i = 0; i < nr_of_days; i++)
            {
                TextBox buton = new TextBox();//null
                createButton(currentPositionX, lastY, buttonWidth, buttonHeight, "Ziua " + (nr_of_aliments + 1).ToString(), ref buton);

                if (i == 1)
                {
                    listaProduse.Add(buton);
                }
                else
                {
                    listaCantitate.Add(buton);
                    lastY += buttonHeight + theGapBetweenButtons;
                }
                hashDeButoane.Add(buton, listaProduse.Count);
            }
            nr_of_aliments++;
        }

        public void createButton(int xPosition, int yPosition, int widthSize, int heightSize, String text, ref TextBox buton)
        {
            //buton = new Button();
            buton.Font = new System.Drawing.Font("Times New Roman", 12.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            buton.Location = new System.Drawing.Point(xPosition, yPosition);
            buton.Name = "button1"; ///kind of random, doesn't mater
            buton.Size = new System.Drawing.Size(widthSize, heightSize);
            buton.TabIndex = 0; ///if you press TAB it will jump to the next button
            buton.Text = "";

            buton.TextChanged += new EventHandler(clickAction);

            panel1.Controls.Add(buton); ///most important, it adds the button to the form
        }

        private void clickAction(object sender, EventArgs e)
        {
            
            //MessageBox.Show(hashDeButoane[(TextBox)sender]); ///object este echivalentul lui void *el din C, deci deaia trebuie sa pun (Button)sender, ca sa ii spun ca sender este defapt un buton
            ///in locul lui (Button) puteam sa pun (TextBox) sau orice altceva
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            addListOfButtons(listaProduse[listaProduse.Count - 1], 1);
            addListOfButtons(listaCantitate[listaCantitate.Count - 1], 2);
        }

        private void buton_vezi_pret_Click(object sender, EventArgs e)
        {
            buton_cumpara_produsele.Enabled = true;
            bool done = false;
            while (!done)
            {
                try
                {
                    System.IO.File.WriteAllText(@"decizie cumparator.txt", "next");
                    done = true;
                }
                catch
                {
                }
            }

            nr_of_iterations = 0;
            //timer1.Start();

            string _produs = "next\n";

            for (int i = 0; i < listaProduse.Count; i++)
            {
                string[] elemente = listaProduse[i].Text.Split(' ');
                _produs += elemente[0] + " " + listaCantitate[i].Text;

                for (int j = 1; j < elemente.Length; j++)
                {
                    _produs += " " + elemente[j];
                }
                _produs += '\n';
            }

            _produs += "finish\n\n";

            string text2 = "";// System.IO.File.ReadAllText("cumparator.txt");

            text2 += _produs;

            done = false;
            while (!done)
            {
                try
                {
                    System.IO.File.WriteAllText(@"cumparator.txt", text2);
                    done = true;
                }
                catch
                {
                }
            }

            nr_of_iterations = 0;
            timer1.Start();

            done = false;
            while (!done)
            {
                try
                {
                    string text = System.IO.File.ReadAllText("pret client curent.txt");
                    MessageBox.Show("Pretul total al alimentelor este: " + text + " de LEI!" + "\n" + "Daca pretul nu apare, mai apasati inca o data pe butonul Vezi Pret, e posibil ca pretul sa nu fi fost calculat inca.");
                    done = true;
                }
                catch
                {
                }
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            bool done = false;
            while (!done)
            {
                try
                {
                    System.IO.File.WriteAllText(@"decizie cumparator.txt", "stop");
                    done = true;
                }
                catch
                {
                }
            }

            int buttonWidth = initial_form.buton_prototip_zi.Size.Width, buttonHeight = initial_form.buton_prototip_zi.Size.Height;
            int theGapBetweenButtons = 15;//15 pixels

            int currentPositionX = initial_form.listaButoane[initial_form.listaButoane.Count - 1].Location.X,
                currentPositionY = initial_form.listaButoane[initial_form.listaButoane.Count - 1].Location.Y + buttonHeight + theGapBetweenButtons;


                Button buton = new Button();//null
                initial_form.createButton(currentPositionX, currentPositionY, buttonWidth, buttonHeight, "Ziua " + (initial_form.listaButoane.Count + 1).ToString(), ref buton);

                initial_form.listaButoane.Add(buton);
                initial_form.hashDeButoane.Add(buton, buton.Text);

                //MessageBox.Show(buton.Text);
                //Debug.WriteLine(buton.Text);

            Close();
        }

        private void buton_cumpara_produsele_Click(object sender, EventArgs e)
        {
            /*
            System.IO.File.WriteAllText(@"decizie cumparator.txt", "next");
            string _produs = "next\n";

            for (int i = 0; i < listaProduse.Count; i++)
            {
                string[] elemente = listaProduse[i].Text.Split(' ');
                _produs += elemente[0] + " " + listaCantitate[i].Text;

                for (int j = 1; j < elemente.Length; j++)
                {
                    _produs += " " + elemente[j];
                }
                _produs += '\n';
            }

            _produs += "finish\n\n";

            string text2 = "";// System.IO.File.ReadAllText("cumparator.txt");

            text2 += _produs;

            System.IO.File.WriteAllText(@"cumparator.txt", text2);*/

            bool done = false;
            while (!done)
            {
                try
                {
                    System.IO.File.WriteAllText(@"decizie cumparator.txt", "da");
                    done = true;
                }
                catch
                {
                }
            }
            buton_cumpara_produsele.Enabled = false;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            bool done = false;
            while (!done)
            {
                try
                {
                    System.IO.File.WriteAllText(@"decizie cumparator.txt", "nu");
                    done = true;
                }
                catch
                {
                }
            }
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            if (nr_of_iterations == 2)
            {
                timer1.Stop();
            }
            nr_of_iterations++;
        }

        private void button4_Click(object sender, EventArgs e)
        {
            Form1 f = new Form1();
        }

        private void Zi_noua_FormClosed(object sender, FormClosedEventArgs e)
        {
            try
            {
                Process[] proc = Process.GetProcessesByName("OOP-LAB");
                proc[0].Kill();
            }
            catch
            {
            }
        }
    }
}
