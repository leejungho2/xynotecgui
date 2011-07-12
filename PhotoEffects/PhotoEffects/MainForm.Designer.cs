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
            this.convolutionToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.mnu_Convolution_Smooth = new System.Windows.Forms.ToolStripMenuItem();
            this.mnu_Convolution_GaussianBlur = new System.Windows.Forms.ToolStripMenuItem();
            this.mnu_Convolution_MeanRemoval = new System.Windows.Forms.ToolStripMenuItem();
            this.mnu_Convolution_Sharpen = new System.Windows.Forms.ToolStripMenuItem();
            this.mnu_Convolution_EmbossLaplacian = new System.Windows.Forms.ToolStripMenuItem();
            this.mnu_Convolution_EdgeDetect = new System.Windows.Forms.ToolStripMenuItem();
            this.mnu_Convolution_Custom = new System.Windows.Forms.ToolStripMenuItem();
            this.displacementFiltersToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.mnu_DisplacementFilter_Flip = new System.Windows.Forms.ToolStripMenuItem();
            this.mnu_DisplacementFilter_RandomJitter = new System.Windows.Forms.ToolStripMenuItem();
            this.mnu_DisplacementFilter_Swirl = new System.Windows.Forms.ToolStripMenuItem();
            this.mnu_DisplacementFilter_Sphere = new System.Windows.Forms.ToolStripMenuItem();
            this.mnu_DisplacementFilter_TimeWarp = new System.Windows.Forms.ToolStripMenuItem();
            this.mnu_DisplacementFilter_Moire = new System.Windows.Forms.ToolStripMenuItem();
            this.mnu_DisplacementFilter_Water = new System.Windows.Forms.ToolStripMenuItem();
            this.mnu_DisplacementFilter_Pixelate = new System.Windows.Forms.ToolStripMenuItem();
            this.panel_Canvas = new System.Windows.Forms.Panel();
            this.mnu_DisplacementFilter_FishEye = new System.Windows.Forms.ToolStripMenuItem();
            this.menuMain.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuMain
            // 
            this.menuMain.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem,
            this.editToolStripMenuItem,
            this.basicEffectsToolStripMenuItem,
            this.convolutionToolStripMenuItem,
            this.displacementFiltersToolStripMenuItem});
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
            this.mnu_File_Open.Size = new System.Drawing.Size(111, 22);
            this.mnu_File_Open.Text = "Open";
            this.mnu_File_Open.Click += new System.EventHandler(this.menuMain_Click);
            // 
            // mnu_File_Save
            // 
            this.mnu_File_Save.Name = "mnu_File_Save";
            this.mnu_File_Save.Size = new System.Drawing.Size(111, 22);
            this.mnu_File_Save.Text = "Save";
            this.mnu_File_Save.Click += new System.EventHandler(this.menuMain_Click);
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            this.toolStripSeparator1.Size = new System.Drawing.Size(108, 6);
            // 
            // mnu_File_Exit
            // 
            this.mnu_File_Exit.Name = "mnu_File_Exit";
            this.mnu_File_Exit.Size = new System.Drawing.Size(111, 22);
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
            this.mnu_Edit_Undo.Size = new System.Drawing.Size(110, 22);
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
            this.mnu_BasicEffects_ColorFilter.Size = new System.Drawing.Size(137, 22);
            this.mnu_BasicEffects_ColorFilter.Text = "Color Filter";
            this.mnu_BasicEffects_ColorFilter.Click += new System.EventHandler(this.menuMain_Click);
            // 
            // mnu_BasicEffects_Gamma
            // 
            this.mnu_BasicEffects_Gamma.Name = "mnu_BasicEffects_Gamma";
            this.mnu_BasicEffects_Gamma.Size = new System.Drawing.Size(137, 22);
            this.mnu_BasicEffects_Gamma.Text = "Gamma";
            this.mnu_BasicEffects_Gamma.Click += new System.EventHandler(this.menuMain_Click);
            // 
            // mnu_BasicEffects_Brightness
            // 
            this.mnu_BasicEffects_Brightness.Name = "mnu_BasicEffects_Brightness";
            this.mnu_BasicEffects_Brightness.Size = new System.Drawing.Size(137, 22);
            this.mnu_BasicEffects_Brightness.Text = "Brightness";
            this.mnu_BasicEffects_Brightness.Click += new System.EventHandler(this.menuMain_Click);
            // 
            // mnu_BasicEffects_Contrast
            // 
            this.mnu_BasicEffects_Contrast.Name = "mnu_BasicEffects_Contrast";
            this.mnu_BasicEffects_Contrast.Size = new System.Drawing.Size(137, 22);
            this.mnu_BasicEffects_Contrast.Text = "Contrast";
            this.mnu_BasicEffects_Contrast.Click += new System.EventHandler(this.menuMain_Click);
            // 
            // mnu_BasicEffects_GrayScale
            // 
            this.mnu_BasicEffects_GrayScale.Name = "mnu_BasicEffects_GrayScale";
            this.mnu_BasicEffects_GrayScale.Size = new System.Drawing.Size(137, 22);
            this.mnu_BasicEffects_GrayScale.Text = "Grayscale";
            this.mnu_BasicEffects_GrayScale.Click += new System.EventHandler(this.menuMain_Click);
            // 
            // mnu_BasicEffects_Invert
            // 
            this.mnu_BasicEffects_Invert.Name = "mnu_BasicEffects_Invert";
            this.mnu_BasicEffects_Invert.Size = new System.Drawing.Size(137, 22);
            this.mnu_BasicEffects_Invert.Text = "Invert";
            this.mnu_BasicEffects_Invert.Click += new System.EventHandler(this.menuMain_Click);
            // 
            // convolutionToolStripMenuItem
            // 
            this.convolutionToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.mnu_Convolution_Smooth,
            this.mnu_Convolution_GaussianBlur,
            this.mnu_Convolution_MeanRemoval,
            this.mnu_Convolution_Sharpen,
            this.mnu_Convolution_EmbossLaplacian,
            this.mnu_Convolution_EdgeDetect,
            this.mnu_Convolution_Custom});
            this.convolutionToolStripMenuItem.Name = "convolutionToolStripMenuItem";
            this.convolutionToolStripMenuItem.Size = new System.Drawing.Size(76, 20);
            this.convolutionToolStripMenuItem.Text = "Convolution";
            // 
            // mnu_Convolution_Smooth
            // 
            this.mnu_Convolution_Smooth.Name = "mnu_Convolution_Smooth";
            this.mnu_Convolution_Smooth.Size = new System.Drawing.Size(167, 22);
            this.mnu_Convolution_Smooth.Text = "Smooth";
            this.mnu_Convolution_Smooth.Click += new System.EventHandler(this.menuMain_Click);
            // 
            // mnu_Convolution_GaussianBlur
            // 
            this.mnu_Convolution_GaussianBlur.Name = "mnu_Convolution_GaussianBlur";
            this.mnu_Convolution_GaussianBlur.Size = new System.Drawing.Size(167, 22);
            this.mnu_Convolution_GaussianBlur.Text = "Gaussian Blur";
            this.mnu_Convolution_GaussianBlur.Click += new System.EventHandler(this.menuMain_Click);
            // 
            // mnu_Convolution_MeanRemoval
            // 
            this.mnu_Convolution_MeanRemoval.Name = "mnu_Convolution_MeanRemoval";
            this.mnu_Convolution_MeanRemoval.Size = new System.Drawing.Size(167, 22);
            this.mnu_Convolution_MeanRemoval.Text = "Mean Removal";
            this.mnu_Convolution_MeanRemoval.Click += new System.EventHandler(this.menuMain_Click);
            // 
            // mnu_Convolution_Sharpen
            // 
            this.mnu_Convolution_Sharpen.Name = "mnu_Convolution_Sharpen";
            this.mnu_Convolution_Sharpen.Size = new System.Drawing.Size(167, 22);
            this.mnu_Convolution_Sharpen.Text = "Sharpen";
            this.mnu_Convolution_Sharpen.Click += new System.EventHandler(this.menuMain_Click);
            // 
            // mnu_Convolution_EmbossLaplacian
            // 
            this.mnu_Convolution_EmbossLaplacian.Name = "mnu_Convolution_EmbossLaplacian";
            this.mnu_Convolution_EmbossLaplacian.Size = new System.Drawing.Size(167, 22);
            this.mnu_Convolution_EmbossLaplacian.Text = "EmbossLaplacian";
            this.mnu_Convolution_EmbossLaplacian.Click += new System.EventHandler(this.menuMain_Click);
            // 
            // mnu_Convolution_EdgeDetect
            // 
            this.mnu_Convolution_EdgeDetect.Name = "mnu_Convolution_EdgeDetect";
            this.mnu_Convolution_EdgeDetect.Size = new System.Drawing.Size(167, 22);
            this.mnu_Convolution_EdgeDetect.Text = "EdgeDetectQuick";
            this.mnu_Convolution_EdgeDetect.Click += new System.EventHandler(this.menuMain_Click);
            // 
            // mnu_Convolution_Custom
            // 
            this.mnu_Convolution_Custom.Name = "mnu_Convolution_Custom";
            this.mnu_Convolution_Custom.Size = new System.Drawing.Size(167, 22);
            this.mnu_Convolution_Custom.Text = "Custom";
            this.mnu_Convolution_Custom.Click += new System.EventHandler(this.menuMain_Click);
            // 
            // displacementFiltersToolStripMenuItem
            // 
            this.displacementFiltersToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.mnu_DisplacementFilter_Flip,
            this.mnu_DisplacementFilter_RandomJitter,
            this.mnu_DisplacementFilter_Swirl,
            this.mnu_DisplacementFilter_Sphere,
            this.mnu_DisplacementFilter_TimeWarp,
            this.mnu_DisplacementFilter_Moire,
            this.mnu_DisplacementFilter_Water,
            this.mnu_DisplacementFilter_Pixelate,
            this.mnu_DisplacementFilter_FishEye});
            this.displacementFiltersToolStripMenuItem.Name = "displacementFiltersToolStripMenuItem";
            this.displacementFiltersToolStripMenuItem.Size = new System.Drawing.Size(114, 20);
            this.displacementFiltersToolStripMenuItem.Text = "Displacement Filters";
            // 
            // mnu_DisplacementFilter_Flip
            // 
            this.mnu_DisplacementFilter_Flip.Name = "mnu_DisplacementFilter_Flip";
            this.mnu_DisplacementFilter_Flip.Size = new System.Drawing.Size(152, 22);
            this.mnu_DisplacementFilter_Flip.Text = "Flip";
            this.mnu_DisplacementFilter_Flip.Click += new System.EventHandler(this.menuMain_Click);
            // 
            // mnu_DisplacementFilter_RandomJitter
            // 
            this.mnu_DisplacementFilter_RandomJitter.Name = "mnu_DisplacementFilter_RandomJitter";
            this.mnu_DisplacementFilter_RandomJitter.Size = new System.Drawing.Size(152, 22);
            this.mnu_DisplacementFilter_RandomJitter.Text = "Random Jitter";
            this.mnu_DisplacementFilter_RandomJitter.Click += new System.EventHandler(this.menuMain_Click);
            // 
            // mnu_DisplacementFilter_Swirl
            // 
            this.mnu_DisplacementFilter_Swirl.Name = "mnu_DisplacementFilter_Swirl";
            this.mnu_DisplacementFilter_Swirl.Size = new System.Drawing.Size(152, 22);
            this.mnu_DisplacementFilter_Swirl.Text = "Swirl";
            this.mnu_DisplacementFilter_Swirl.Click += new System.EventHandler(this.menuMain_Click);
            // 
            // mnu_DisplacementFilter_Sphere
            // 
            this.mnu_DisplacementFilter_Sphere.Name = "mnu_DisplacementFilter_Sphere";
            this.mnu_DisplacementFilter_Sphere.Size = new System.Drawing.Size(152, 22);
            this.mnu_DisplacementFilter_Sphere.Text = "Sphere";
            this.mnu_DisplacementFilter_Sphere.Click += new System.EventHandler(this.menuMain_Click);
            // 
            // mnu_DisplacementFilter_TimeWarp
            // 
            this.mnu_DisplacementFilter_TimeWarp.Name = "mnu_DisplacementFilter_TimeWarp";
            this.mnu_DisplacementFilter_TimeWarp.Size = new System.Drawing.Size(152, 22);
            this.mnu_DisplacementFilter_TimeWarp.Text = "Time Warp";
            this.mnu_DisplacementFilter_TimeWarp.Click += new System.EventHandler(this.menuMain_Click);
            // 
            // mnu_DisplacementFilter_Moire
            // 
            this.mnu_DisplacementFilter_Moire.Name = "mnu_DisplacementFilter_Moire";
            this.mnu_DisplacementFilter_Moire.Size = new System.Drawing.Size(152, 22);
            this.mnu_DisplacementFilter_Moire.Text = "Moire";
            this.mnu_DisplacementFilter_Moire.Click += new System.EventHandler(this.menuMain_Click);
            // 
            // mnu_DisplacementFilter_Water
            // 
            this.mnu_DisplacementFilter_Water.Name = "mnu_DisplacementFilter_Water";
            this.mnu_DisplacementFilter_Water.Size = new System.Drawing.Size(152, 22);
            this.mnu_DisplacementFilter_Water.Text = "Water";
            this.mnu_DisplacementFilter_Water.Click += new System.EventHandler(this.menuMain_Click);
            // 
            // mnu_DisplacementFilter_Pixelate
            // 
            this.mnu_DisplacementFilter_Pixelate.Name = "mnu_DisplacementFilter_Pixelate";
            this.mnu_DisplacementFilter_Pixelate.Size = new System.Drawing.Size(152, 22);
            this.mnu_DisplacementFilter_Pixelate.Text = "Pixelate";
            this.mnu_DisplacementFilter_Pixelate.Click += new System.EventHandler(this.menuMain_Click);
            // 
            // panel_Canvas
            // 
            this.panel_Canvas.AutoScroll = true;
            this.panel_Canvas.Dock = System.Windows.Forms.DockStyle.Fill;
            this.panel_Canvas.Location = new System.Drawing.Point(0, 24);
            this.panel_Canvas.Name = "panel_Canvas";
            this.panel_Canvas.Size = new System.Drawing.Size(646, 360);
            this.panel_Canvas.TabIndex = 1;
            this.panel_Canvas.Paint += new System.Windows.Forms.PaintEventHandler(this.panel_Canvas_Paint);
            // 
            // mnu_DisplacementFilter_FishEye
            // 
            this.mnu_DisplacementFilter_FishEye.Name = "mnu_DisplacementFilter_FishEye";
            this.mnu_DisplacementFilter_FishEye.Size = new System.Drawing.Size(152, 22);
            this.mnu_DisplacementFilter_FishEye.Text = "Fish Eye";
            this.mnu_DisplacementFilter_FishEye.Click += new System.EventHandler(this.menuMain_Click);
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ControlLight;
            this.ClientSize = new System.Drawing.Size(646, 384);
            this.Controls.Add(this.panel_Canvas);
            this.Controls.Add(this.menuMain);
            this.MainMenuStrip = this.menuMain;
            this.Name = "MainForm";
            this.Text = "MainForm";
            this.WindowState = System.Windows.Forms.FormWindowState.Maximized;
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
        private System.Windows.Forms.Panel panel_Canvas;
        private System.Windows.Forms.ToolStripMenuItem convolutionToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem mnu_Convolution_Smooth;
        private System.Windows.Forms.ToolStripMenuItem mnu_Convolution_GaussianBlur;
        private System.Windows.Forms.ToolStripMenuItem mnu_Convolution_MeanRemoval;
        private System.Windows.Forms.ToolStripMenuItem mnu_Convolution_Sharpen;
        private System.Windows.Forms.ToolStripMenuItem mnu_Convolution_EmbossLaplacian;
        private System.Windows.Forms.ToolStripMenuItem mnu_Convolution_EdgeDetect;
        private System.Windows.Forms.ToolStripMenuItem mnu_Convolution_Custom;
        private System.Windows.Forms.ToolStripMenuItem displacementFiltersToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem mnu_DisplacementFilter_Flip;
        private System.Windows.Forms.ToolStripMenuItem mnu_DisplacementFilter_RandomJitter;
        private System.Windows.Forms.ToolStripMenuItem mnu_DisplacementFilter_Swirl;
        private System.Windows.Forms.ToolStripMenuItem mnu_DisplacementFilter_Sphere;
        private System.Windows.Forms.ToolStripMenuItem mnu_DisplacementFilter_TimeWarp;
        private System.Windows.Forms.ToolStripMenuItem mnu_DisplacementFilter_Moire;
        private System.Windows.Forms.ToolStripMenuItem mnu_DisplacementFilter_Water;
        private System.Windows.Forms.ToolStripMenuItem mnu_DisplacementFilter_Pixelate;
        private System.Windows.Forms.ToolStripMenuItem mnu_DisplacementFilter_FishEye;
    }
}

