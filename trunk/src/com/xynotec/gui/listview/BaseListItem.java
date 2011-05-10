package com.xynotec.gui.listview;


import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;

public abstract interface BaseListItem 
{
	  public abstract int getListElementLayoutId();

	  public abstract View getViewForListElement(LayoutInflater paramLayoutInflater, Context paramContext, View paramView);

	  public abstract boolean isListElementClickable();
}
