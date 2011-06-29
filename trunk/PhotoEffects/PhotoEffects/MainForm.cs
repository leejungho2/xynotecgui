using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Imaging;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using ImageEffect;

namespace PhotoEffects
{
    public partial class MainForm : Form
    {
        private System.Drawing.Bitmap m_Bitmap;
        private System.Drawing.Bitmap m_Undo;
        private double Zoom = 1.0;

        private ImageEffect.ApplyBasicEffect basicEffect;

        public MainForm()
        {
            InitializeComponent();
            basicEffect = new ImageEffect.ApplyBasicEffect(m_Bitmap);
        }

        private void MainForm_Paint(object sender, PaintEventArgs e)
        {
            if (m_Bitmap != null)
            {
                Graphics g = e.Graphics;
                g.DrawImage(m_Bitmap, new Rectangle(this.AutoScrollPosition.X, this.AutoScrollPosition.Y, (int)(m_Bitmap.Width * Zoom), (int)(m_Bitmap.Height * Zoom)));
            }            
        }

        private void menuMain_Click(object sender, EventArgs e)
        {
            if (sender == mnu_File_Open)
            {
                File_Open();
            }
            else if (sender == mnu_File_Save)
            {
                File_Save();
            }
            else if (sender == mnu_File_Exit)
            {
                File_Exit();
            }
            else if (sender == mnu_Edit_Undo)
            {
                Edit_Undo();
            }
            else if (sender == mnu_BasicEffects_ColorFilter)
            {
                BasicEffects_ColorFilter();
            }
            else if (sender == mnu_BasicEffects_Gamma)
            {
                BasicEffects_Gamma();
            }
            else if (sender == mnu_BasicEffects_Brightness)
            {
                BasicEffects_Brightness();
            }
            else if (sender == mnu_BasicEffects_Contrast)
            {
                BasicEffects_Contrast();
            }
            else if (sender == mnu_BasicEffects_GrayScale)
            {
                BasicEffects_GrayScale();
            }
            else if (sender == mnu_BasicEffects_Invert)
            {
                BasicEffects_Invert();
            }
        }

#region MenuItem Event

        private void File_Open()
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();

            //openFileDialog.InitialDirectory = "c:\\";
            openFileDialog.Filter = "Bitmap files (*.bmp)|*.bmp|Jpeg files (*.jpg)|*.jpg|All valid files (*.bmp/*.jpg)|*.bmp/*.jpg| All Files|*.*";
            openFileDialog.FilterIndex = 4;
            openFileDialog.RestoreDirectory = true;

            if (DialogResult.OK == openFileDialog.ShowDialog())
            {
                m_Bitmap = (Bitmap)Bitmap.FromFile(openFileDialog.FileName, false);
                this.AutoScroll = true;
                this.AutoScrollMinSize = new Size((int)(m_Bitmap.Width * Zoom), (int)(m_Bitmap.Height * Zoom));
                this.Invalidate();
            }
        }

        private void File_Save()
        {
            SaveFileDialog saveFileDialog = new SaveFileDialog();

            saveFileDialog.InitialDirectory = "c:\\";
            saveFileDialog.Filter = "Bitmap files (*.bmp)|*.bmp|Jpeg files (*.jpg)|*.jpg|All valid files (*.bmp/*.jpg)|*.bmp/*.jpg";
            saveFileDialog.FilterIndex = 1;
            saveFileDialog.RestoreDirectory = true;

            if (DialogResult.OK == saveFileDialog.ShowDialog())
            {
                switch (saveFileDialog.FileName.Substring(saveFileDialog.FileName.Length - 3, 3).ToLower())
                {
                    case "bmp":
                        m_Bitmap.Save(saveFileDialog.FileName, ImageFormat.Bmp);
                        break;
                    case "png":
                        m_Bitmap.Save(saveFileDialog.FileName, ImageFormat.Png);
                        break;
                    case "jpg":
                    case "jpe":
                    case "peg":
                        m_Bitmap.Save(saveFileDialog.FileName, ImageFormat.Jpeg);
                        break;
                    case "tif":
                    case "iff":
                        m_Bitmap.Save(saveFileDialog.FileName, ImageFormat.Tiff);
                        break;
                }
            }
        }

        private void File_Exit()
        {
            this.Close();
        }

        private void Edit_Undo()
        {
            Bitmap temp = (Bitmap)m_Bitmap.Clone();
            m_Bitmap = (Bitmap)m_Undo.Clone();
            m_Undo = (Bitmap)temp.Clone();
            this.Invalidate();
        }

        private void BasicEffects_ColorFilter()
        {
            m_Undo = (Bitmap)m_Bitmap.Clone();

            basicEffect.SetImage(m_Bitmap);
            basicEffect.ApplyColorFilter(Color_Filter.Color_Green);

            this.Invalidate();
        }
        
        private void BasicEffects_Gamma()
        {
            m_Undo = (Bitmap)m_Bitmap.Clone();

            basicEffect.SetImage(m_Bitmap);
            //value 0->1
            basicEffect.ApplyGamma(0.5, 0.5, 0.5);

            this.Invalidate();
        }
        
        private void BasicEffects_Brightness()
        {
            m_Undo = (Bitmap)m_Bitmap.Clone();

            basicEffect.SetImage(m_Bitmap);
            //value -255->255
            basicEffect.ApplyBrightness(-100);

            this.Invalidate();
        }
                
        private void BasicEffects_Contrast()
        {
            m_Undo = (Bitmap)m_Bitmap.Clone();

            basicEffect.SetImage(m_Bitmap);
            //value -100->100
            basicEffect.ApplyContrast(-50);

            this.Invalidate();
        }
            
        private void BasicEffects_GrayScale()
        {
            m_Undo = (Bitmap)m_Bitmap.Clone();

            basicEffect.SetImage(m_Bitmap);
            basicEffect.ApplyGrayscale();

            this.Invalidate();
        }

        private void BasicEffects_Invert()
        {
            m_Undo = (Bitmap)m_Bitmap.Clone();

            basicEffect.SetImage(m_Bitmap);
            basicEffect.ApplyInvert();

            this.Invalidate();

        }

#endregion

  
    }
}
