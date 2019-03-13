using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace LopendeBand
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btnStartProd_Click(object sender, EventArgs e)
        {
            try
            {
                serialPort.Write("#btn:Start%"); //send 1 to Arduino
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }

        }

        private void btnStopProd_Click(object sender, EventArgs e)
        {
            try
            {
                serialPort.Write("#btn:Stop%"); //send 0 to Arduino
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }

        }

        private void btnServo_Click(object sender, EventArgs e)
        {
            try
            {
                serialPort.Write("#btn:Servo%"); //send 2 to Arduino
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }

        }

        private void btnConnect_Click(object sender, EventArgs e)
        {
            try
            {
                serialPort.Open();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }

        }

        private void btnDisconnect_Click(object sender, EventArgs e)
        {
            serialPort.Close();
        }
    }
}
