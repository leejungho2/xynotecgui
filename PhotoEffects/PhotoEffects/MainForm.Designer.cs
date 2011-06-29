namespace PhotoEffects
{
    partial class MainForm
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
            this.menuMain = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.mnu_File_Open = new System.Windows.Forms.ToolStripMenuItem();
            this.mnu_File_Save = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.mnu_File_Exit = new System.Windows.Forms.ToolStripMenuItem();
            this.editToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.mnu_Edit_Undo = new System.Windows.Forms.ToolStripMenuItem();
            this.basicEffectsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.mnu_BasicEffects_ColorFilter = new System.Windows.Forms.ToolStripMenuItem();
            this.mnu_BasicEffects_Gamma = new System.Windows.Forms.ToolStripMenuItem();
            this.mnu_BasicEffects_Brightness = new System.Windows.Forms.ToolStripMenuItem();
            this.mnu_BasicEffects_Contrast = new System.Windows.Forms.ToolStripMenuItem();
            this.mnu_BasicEffects_GrayScale = new System.Windows.Forms.ToolStripMenuItem();
            this.mnu_BasicEffects_Invert = new System.Windows.Forms.ToolStripMenuItem();
            this.menuMain.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuMain
            // 
            this.menuMain.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem,
            this.editToolStripMenuItem,
            this.basicEffectsToolStripMenuItem});
            this.menuMain.Location = new System.Drawing.Point(0, 0);
            this.menuMain.Name = "menuMain";
            this.menuMain.Size = new System.Drawing.Size(646, 24);
            this.menuMain.TabIndex = 0;
            this.menuMain.Text = "menuStrip1";
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.mnu_File_Open,
            this.mnu_File_Save,
            this.toolStripSeparator1,
            this.mnu_File_Exit});
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            this.fileToolStripMenuItem.Size = new System.Drawing.Size(35, 20);
            this.fileToolStripMenuItem.Text = "File";
            // 
            // mnu_File_Open
            // 
            this.mnu_File_Open.Name = "mnu_File_Open";
            this.mnu_File_Open.Size = new System.Drawing.Size(152, 22);
            this.mnu_File_Open.Text = "Open";
            this.mnu_File_Open.Click += new System.EventHandler(this.menuMain_Click);
            // 
            // mnu_File_Save
            // 
            this.mnu_File_Save.Name = "mnu_File_Save";
            this.mnu_File_Save.Size = new System.Drawing.Size(152, 22);
            this.mnu_File_Save.Text = "Save";
            this.mnu_File_Save.Click += new System.EventHandler(this.menuMain_Click);
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            this.toolStripSeparator1.Size = new System.Drawing.Size(149, 6);
            // 
            // mnu_File_Exit
            // 
            this.mnu_File_Exit.Name = "mnu_File_Exit";
            this.mnu_File_Exit.Size = new System.Drawing.Size(152, 22);
            this.mnu_File_Exit.Text = "Exit";
            this.mnu_File_Exit.Click += new System.EventHandler(this.menuMain_Click);
            // 
            // editToolStripMenuItem
            // 
            this.editToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.mnu_Edit_Undo});
            this.editToolStripMenuItem.Name = "editToolStripMenuItem";
            this.editToolStripMenuItem.Size = new System.Drawing.Size(37, 20);
            this.editToolStripMenuItem.Text = "Edit";
            // 
            // mnu_Edit_Undo
            // 
            this.mnu_Edit_Undo.Name = "mnu_Edit_Undo";
            this.mnu_Edit_Undo.Size = new System.Drawing.Size(152, 22);
            this.mnu_Edit_Undo.Text = "Undo";
            this.mnu_Edit_Undo.Click += new System.EventHandler(this.menuMain_Click);
            // 
            // basicEffectsToolStripMenuItem
            // 
            this.basicEffectsToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.mnu_BasicEffects_ColorFilter,
            this.mnu_BasicEffects_Gamma,
            this.mnu_BasicEffects_Brightness,
            this.mnu_BasicEffects_Contrast,
            this.mnu_BasicEffects_GrayScale,
            this.mnu_BasicEffects_Invert});
            this.basicEffectsToolStripMenuItem.Name = "basicEffectsToolStripMenuItem";
            this.basicEffectsToolStripMenuItem.Size = new System.Drawing.Size(80, 20);
            this.basicEffectsToolStripMenuItem.Text = "Basic Effects";
            // 
            // mnu_BasicEffects_ColorFilter
            // 
            this.mnu_BasicEffects_ColorFilter.Name = "mnu_BasicEffects_ColorFilter";
            this.mnu_BasicEffects_ColorFilter.Size = new System.Drawing.Size(152, 22);
            this.mnu_BasicEffects_ColorFilter.Text = "Color Filter";
            this.mnu_BasicEffects_ColorFilter.Click += new System.EventHandler(this.menuMain_Click);
            // 
            // mnu_BasicEffects_Gamma
            // 
            this.mnu_BasicEffects_Gamma.Name = "mnu_BasicEffects_Gamma";
            this.mnu_BasicEffects_Gamma.Size = new System.Drawing.Size(152, 22);
            this.mnu_BasicEffects_Gamma.Text = "Gamma";
            this.mnu_BasicEffects_Gamma.Click += new System.EventHandler(this.menuMain_Click);
            // 
            // mnu_BasicEffects_Brightness
            // 
            this.mnu_BasicEffects_Brightness.Name = "mnu_BasicEffects_Brightness";
            this.mnu_BasicEffects_Brightness.Size = new System.Drawing.Size(152, 22);
            this.mnu_BasicEffects_Brightness.Text = "Brightness";
            this.mnu_BasicEffects_Brightness.Click += new System.EventHandler(this.menuMain_Click);
            // 
            // mnu_BasicEffects_Contrast
            // 
            this.mnu_BasicEffects_Contrast.Name = "mnu_BasicEffects_Contrast";
            this.mnu_BasicEffects_Contrast.Size = new System.Drawing.Size(152, 22);
            this.mnu_BasicEffects_Contrast.Text = "Contrast";
            this.mnu_BasicEffects_Contrast.Click += new System.EventHandler(this.menuMain_Click);
            // 
            // mnu_BasicEffects_GrayScale
            // 
            this.mnu_BasicEffects_GrayScale.Name = "mnu_BasicEffects_GrayScale";
            this.mnu_BasicEffects_GrayScale.Size = new System.Drawing.Size(152, 22);
            this.mnu_BasicEffects_GrayScale.Text = "Grayscale";
            this.mnu_BasicEffects_GrayScale.Click += new System.EventHandler(this.menuMain_Click);
            // 
            // mnu_BasicEffects_Invert
            // 
            this.mnu_BasicEffects_Invert.Name = "mnu_BasicEffects_Invert";
            this.mnu_BasicEffects_Invert.Size = new System.Drawing.Size(152, 22);
            this.mnu_BasicEffects_Invert.Text = "Invert";
            this.mnu_BasicEffects_Invert.Click += new System.EventHandler(this.menuMain_Click);
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ControlLight;
            this.ClientSize = new System.Drawing.Size(646, 384);
            this.Controls.Add(this.menuMain);
            this.MainMenuStrip = this.menuMain;
            this.Name = "MainForm";
            this.Text = "MainForm";
            this.WindowState = System.Windows.Forms.FormWindowState.Maximized;
            this.Paint += new System.Windows.Forms.PaintEventHandler(this.MainForm_Paint);
            this.menuMain.ResumeLayout(false);
            this.menuMain.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuMain;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem mnu_File_Open;
        private System.Windows.Forms.ToolStripMenuItem mnu_File_Save;
        private System.Windows.Forms.ToolStripMenuItem mnu_File_Exit;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
        private System.Windows.Forms.ToolStripMenuItem editToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem mnu_Edit_Undo;
        private System.Windows.Forms.ToolStripMenuItem basicEffectsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem mnu_BasicEffects_ColorFilter;
        private System.Windows.Forms.ToolStripMenuItem mnu_BasicEffects_Gamma;
        private System.Windows.Forms.ToolStripMenuItem mnu_BasicEffects_Brightness;
        private System.Windows.Forms.ToolStripMenuItem mnu_BasicEffects_Contrast;
        private System.Windows.Forms.ToolStripMenuItem mnu_BasicEffects_GrayScale;
        private System.Windows.Forms.ToolStripMenuItem mnu_BasicEffects_Invert;
    }
}

