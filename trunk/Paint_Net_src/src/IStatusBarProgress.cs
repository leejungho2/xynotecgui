﻿/////////////////////////////////////////////////////////////////////////////////
// Paint.NET                                                                   //
// Copyright (C) Rick Brewster, Tom Jackson, and past contributors.            //
// Portions Copyright (C) Microsoft Corporation. All Rights Reserved.          //
// See src/Resources/Files/License.txt for full licensing and attribution      //
// details.                                                                    //
// .                                                                           //
/////////////////////////////////////////////////////////////////////////////////

using System;

namespace PaintDotNet
{
    public interface IStatusBarProgress
    {
        void EraseProgressStatusBar();
        void EraseProgressStatusBarAsync();
        double GetProgressStatusBarValue();
        void ResetProgressStatusBar();
        void ResetProgressStatusBarAsync();
        void SetProgressStatusBar(double percent);
    }
}
