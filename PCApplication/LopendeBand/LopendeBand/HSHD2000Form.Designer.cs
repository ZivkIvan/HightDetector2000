namespace LopendeBand
{
    partial class Form1
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
            this.components = new System.ComponentModel.Container();
            this.btnStartProd = new System.Windows.Forms.Button();
            this.btnServo = new System.Windows.Forms.Button();
            this.btnStopProd = new System.Windows.Forms.Button();
            this.serialPort = new System.IO.Ports.SerialPort(this.components);
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.btnConnect = new System.Windows.Forms.Button();
            this.btnDisconnect = new System.Windows.Forms.Button();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.SuspendLayout();
            // 
            // btnStartProd
            // 
            this.btnStartProd.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(192)))), ((int)(((byte)(0)))));
            this.btnStartProd.Location = new System.Drawing.Point(14, 21);
            this.btnStartProd.Name = "btnStartProd";
            this.btnStartProd.Size = new System.Drawing.Size(116, 23);
            this.btnStartProd.TabIndex = 0;
            this.btnStartProd.Text = "Start Production";
            this.btnStartProd.UseVisualStyleBackColor = false;
            this.btnStartProd.Click += new System.EventHandler(this.btnStartProd_Click);
            // 
            // btnServo
            // 
            this.btnServo.BackColor = System.Drawing.Color.Yellow;
            this.btnServo.Location = new System.Drawing.Point(14, 79);
            this.btnServo.Name = "btnServo";
            this.btnServo.Size = new System.Drawing.Size(116, 23);
            this.btnServo.TabIndex = 1;
            this.btnServo.Text = "Move Servo";
            this.btnServo.UseVisualStyleBackColor = false;
            this.btnServo.Click += new System.EventHandler(this.btnServo_Click);
            // 
            // btnStopProd
            // 
            this.btnStopProd.BackColor = System.Drawing.Color.Red;
            this.btnStopProd.Location = new System.Drawing.Point(14, 50);
            this.btnStopProd.Name = "btnStopProd";
            this.btnStopProd.Size = new System.Drawing.Size(116, 23);
            this.btnStopProd.TabIndex = 2;
            this.btnStopProd.Text = "Stop Production";
            this.btnStopProd.UseVisualStyleBackColor = false;
            this.btnStopProd.Click += new System.EventHandler(this.btnStopProd_Click);
            // 
            // serialPort
            // 
            this.serialPort.PortName = "COM100";
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.btnConnect);
            this.groupBox1.Controls.Add(this.btnDisconnect);
            this.groupBox1.Location = new System.Drawing.Point(12, 12);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(147, 88);
            this.groupBox1.TabIndex = 21;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Arduino";
            // 
            // btnConnect
            // 
            this.btnConnect.Location = new System.Drawing.Point(14, 21);
            this.btnConnect.Name = "btnConnect";
            this.btnConnect.Size = new System.Drawing.Size(116, 23);
            this.btnConnect.TabIndex = 16;
            this.btnConnect.Text = "Connect";
            this.btnConnect.UseVisualStyleBackColor = true;
            this.btnConnect.Click += new System.EventHandler(this.btnConnect_Click);
            // 
            // btnDisconnect
            // 
            this.btnDisconnect.Location = new System.Drawing.Point(14, 50);
            this.btnDisconnect.Name = "btnDisconnect";
            this.btnDisconnect.Size = new System.Drawing.Size(116, 23);
            this.btnDisconnect.TabIndex = 10;
            this.btnDisconnect.Text = "Disconnect";
            this.btnDisconnect.UseVisualStyleBackColor = true;
            this.btnDisconnect.Click += new System.EventHandler(this.btnDisconnect_Click);
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.btnServo);
            this.groupBox2.Controls.Add(this.btnStopProd);
            this.groupBox2.Controls.Add(this.btnStartProd);
            this.groupBox2.Location = new System.Drawing.Point(12, 106);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(147, 121);
            this.groupBox2.TabIndex = 22;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Production";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(170, 238);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Name = "Form1";
            this.Text = "HSHD2000";
            this.groupBox1.ResumeLayout(false);
            this.groupBox2.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button btnStartProd;
        private System.Windows.Forms.Button btnServo;
        private System.Windows.Forms.Button btnStopProd;
        private System.IO.Ports.SerialPort serialPort;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Button btnConnect;
        private System.Windows.Forms.Button btnDisconnect;
        private System.Windows.Forms.GroupBox groupBox2;
    }
}

