package com.xynotec.gui.listview;

import android.view.View;

public abstract interface ClickableItem
{
  public abstract View.OnClickListener getViewOnClickAction();

  public abstract void setViewOnClickAction(View.OnClickListener paramOnClickListener);
}

