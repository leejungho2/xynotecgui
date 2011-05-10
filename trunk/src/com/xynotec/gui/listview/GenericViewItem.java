package com.xynotec.gui.listview;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;

public abstract class GenericViewItem
  implements BaseListItem
{
  public int getListElementLayoutId()
  {
    return 0;
  }

  public abstract View getView();

  public View getViewForListElement(LayoutInflater paramLayoutInflater, Context paramContext, View paramView)
  {
    return getView();
  }

  public boolean isListElementClickable()
  {
    return true;
  }
}

