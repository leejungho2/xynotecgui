package com.xynotec.gui.listview;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;

import com.xynotec.gui.R;

public class LinkItem
  implements BaseListItem
{
  private View.OnClickListener clickAction;
  private String text;

  public LinkItem()
  {
  }

  public LinkItem(String textString, View.OnClickListener paramOnClickListener)
  {
    this.text = textString;
    this.clickAction = paramOnClickListener;
  }

  public View.OnClickListener getClickAction()
  {
    return this.clickAction;
  }

  public int getListElementLayoutId()
  {
    return R.layout.link_list_item;
  }

  public String getText()
  {
    return this.text;
  }

  public View getViewForListElement(LayoutInflater layoutinflater, Context context, View view)
  {
      ImageView imageview;
      ClickableRelativeLayout clickablerelativelayout = null;
      String s;
      android.view.View.OnClickListener onclicklistener;
      if(view == null)
      {
          int i = getListElementLayoutId();
          clickablerelativelayout = (ClickableRelativeLayout)layoutinflater.inflate(i, null);
      } 
      else
      {
          clickablerelativelayout = (ClickableRelativeLayout)view;
      }
      s = getText();
      text = s;
      if(s != null)
      {
          TextView textview = (TextView)clickablerelativelayout.findViewById(com.xynotec.gui.R.id.label);
          String s1 = text;
          textview.setText(s1);
      }
      imageview = (ImageView)clickablerelativelayout.findViewById(com.xynotec.gui.R.id.accessory);
      if (clickAction == null)
      {
    	  if(imageview != null)
              imageview.setVisibility(View.GONE);
      }
      else
      {
          onclicklistener = clickAction;
          clickablerelativelayout.setViewOnClickAction(onclicklistener);
          if(imageview != null)
              imageview.setVisibility(View.INVISIBLE);    	  
      }      
      return clickablerelativelayout;      
  }

  public boolean isListElementClickable()
  {
    return true;
  }

  public void setClickAction(View.OnClickListener paramOnClickListener)
  {
    this.clickAction = paramOnClickListener;
  }

  public void setText(String paramString)
  {
    this.text = paramString;
  }
}

