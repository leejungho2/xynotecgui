package com.xynotec.gui.listview;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.TextView;

public class BoldLinkItem extends LinkItem
{
  private String extra;

  public BoldLinkItem()
  {
  }

  public BoldLinkItem(String textString, String textExString, View.OnClickListener paramOnClickListener)
  {
    super(textString, paramOnClickListener);
    this.extra = textExString;
  }

  public String getExtra()
  {
    return this.extra;
  }

  public int getListElementLayoutId()
  {
    return com.xynotec.gui.R.layout.bold_link_list_item;
  }

  public View getViewForListElement(LayoutInflater paramLayoutInflater, Context paramContext, View paramView)
  {
    ClickableRelativeLayout localClickableRelativeLayout = (ClickableRelativeLayout)super.getViewForListElement(paramLayoutInflater, paramContext, paramView);
    TextView localTextView = (TextView)localClickableRelativeLayout.findViewById(com.xynotec.gui.R.id.extra);
    String str = this.extra;
    localTextView.setText(str);
    return localClickableRelativeLayout;
  }

  public void setExtra(String paramString)
  {
    this.extra = paramString;
  }
}
