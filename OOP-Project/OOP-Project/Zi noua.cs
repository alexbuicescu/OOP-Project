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
        public List<TextBox> listaProduse_textBox = new List<TextBox>();
        public List<TextBox> listaCantitati_textBox = new List<TextBox>();
        int the_gap_between_controls = 15;//15 pixels

        int lastY;

        int nr_of_aliments = 0;

        Magazin initial_form;

        public Zi_noua(Magazin formul_initial)
        {
            InitializeComponent();

            //vad de unde vin, ca sa stiu in ce form modific dupa ce am inchis ziua (pentru a adauga o zi noua)
            initial_form = formul_initial;

            //vad care este pozitia Y la care se afla textBox-ul pus de mine in form
            lastY = textBox1.Location.Y;
            
            //creez textboxurile initiale pentru produse
            add_new_field_for_produs(textBox1, 1);
            add_new_field_for_produs(textBox2, 2);

            //pornesc programul din c++
            ProcessStartInfo startInfo = new ProcessStartInfo();
            startInfo.FileName = "OOP-LAB.exe";
            Process.Start(startInfo);
        }


        public void add_new_field_for_produs(TextBox _text_box, int i)
        {
            int currentPositionX = _text_box.Location.X;
            int control_width = _text_box.Size.Width, control_height = _text_box.Size.Height;

            TextBox _textBox_nou = new TextBox();//null
            createButton(currentPositionX, lastY, control_width, control_height, ref _textBox_nou);

            //daca adaug un field pentru numele produsului
            if (i == 1)
            {
                listaProduse_textBox.Add(_textBox_nou);
            }
            //daca adaug un field pentru cantitatea produsului
            else
            {
                listaCantitati_textBox.Add(_textBox_nou);
                lastY += control_height + the_gap_between_controls;
            }
            nr_of_aliments++;
        }

        public void createButton(int xPosition, int yPosition, int widthSize, int heightSize, ref TextBox _textBox_nou)
        {
            _textBox_nou.Font = new System.Drawing.Font("Times New Roman", 12.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            _textBox_nou.Location = new System.Drawing.Point(xPosition, yPosition);
            _textBox_nou.Size = new System.Drawing.Size(widthSize, heightSize);
            _textBox_nou.TabIndex = 0; ///if you press TAB it will jump to the next button
            _textBox_nou.Text = "";

            _textBox_nou.TextChanged += new EventHandler(textChangedAction);

            panel1.Controls.Add(_textBox_nou);
        }

        private void textChangedAction(object sender, EventArgs e)
        {
        }

        private void adauga_produs_buton_Click(object sender, EventArgs e)
        {
            add_new_field_for_produs(listaProduse_textBox[listaProduse_textBox.Count - 1], 1);
            add_new_field_for_produs(listaCantitati_textBox[listaCantitati_textBox.Count - 1], 2);
        }

        private void buton_vezi_pret_Click(object sender, EventArgs e)
        {
            buton_cumpara_produsele.Enabled = true;
            buton_cumpara_produsele.BackColor = System.Drawing.Color.LightSteelBlue;

            //incerc sa imi scriu raspunsul in fisier
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

            string _produs = "next\n";
            //scriu in fisier care sunt produsele pe care vreau sa le cumpar
            for (int i = 0; i < listaProduse_textBox.Count; i++)
            {
                if (listaProduse_textBox[i].Text != "")
                {
                    string[] elemente = listaProduse_textBox[i].Text.Split(' ');
                    _produs += elemente[0] + " " + listaCantitati_textBox[i].Text;

                    for (int j = 1; j < elemente.Length; j++)
                    {
                        _produs += " " + elemente[j];
                    }
                    _produs += '\n';
                }
            }

            _produs += "finish\n\n";

            //incerc sa scriu in fisier produsele dorite
            done = false;
            while (!done)
            {
                try
                {
                    System.IO.File.WriteAllText(@"cumparator.txt", _produs);
                    done = true;
                }
                catch
                {
                }
            }

            //MessageBox.Show(_produs);

            //ii dau un sleep mic, ca sa las C++ sa termine operatiile
            System.Threading.Thread.Sleep(100);
            //incerc sa citesc pretul total - ATENTIE!! e posibil ca C++ sa nu fi terminat de calculat pretul, si nu se va afisa un pret, in acest caz, se va apasa din nou pe butonul "Vezi Pret"
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

        private void inchide_ziua_buton_Click(object sender, EventArgs e)
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

            int control_width = initial_form.buton_prototip_zi.Size.Width, control_height = initial_form.buton_prototip_zi.Size.Height;

            int current_position_x = initial_form.listaZile_button[initial_form.listaZile_button.Count - 1].Location.X,
                current_position_y = initial_form.listaZile_button[initial_form.listaZile_button.Count - 1].Location.Y + control_height + the_gap_between_controls;

            //adaug o zi noua in formul principal
            Button control = new Button();//null
            initial_form.createButton(current_position_x, current_position_y, control_width, control_height, "Ziua " + (initial_form.listaZile_button.Count + 1).ToString(), ref control);

            initial_form.listaZile_button.Add(control);

            //ii dau un sleep mic, ca sa las C++ sa termine operatiile
            System.Threading.Thread.Sleep(100);
            Close();
        }

        private void buton_cumpara_produsele_Click(object sender, EventArgs e)
        {
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
            buton_cumpara_produsele.BackColor = System.Drawing.Color.Gold;
        }

        private void sterge_produsele_buton_Click(object sender, EventArgs e)
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
