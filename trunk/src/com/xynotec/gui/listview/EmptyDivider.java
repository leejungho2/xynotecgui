package com.xynotec.gui.listview;

import com.xynotec.gui.R;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;

public class EmptyDivider implements BaseListItem
{

	@Override
	public int getListElementLayoutId()
	{
		// TODO Auto-generated method stub
		return R.layout.divider;
	}

	@Override
	public View getViewForListElement(LayoutInflater paramLayoutInflater,
			Context paramContext, View paramView)
	{
		// TODO Auto-generated method stub
	      View localView = paramView;
	      if (localView == null)
	      {
	        int i = getListElementLayoutId();
	        localView = paramLayoutInflater.inflate(i, null);
	      }
	      return localView;
	}

	@Override
	public boolean isListElementClickable()
	{
		// TODO Auto-generated method stub
		return false;
	}

}
