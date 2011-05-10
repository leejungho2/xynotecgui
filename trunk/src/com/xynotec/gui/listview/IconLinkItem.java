package com.xynotec.gui.listview;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.ImageView;

public class IconLinkItem extends LinkItem
{
  private int imageId;

  public IconLinkItem()
  {
  }

  public IconLinkItem(int paramInt, String paramString, View.OnClickListener paramOnClickListener)
  {
    super(paramString, paramOnClickListener);
    this.imageId = paramInt;
  }

  public int getImageId()
  {
    return this.imageId;
  }

  public int getListElementLayoutId()
  {
    return com.xynotec.gui.R.layout.icon_label_list_item;
  }

  public View getViewForListElement(LayoutInflater paramLayoutInflater, Context paramContext, View paramView)
  {
    ClickableRelativeLayout localClickableRelativeLayout = (ClickableRelativeLayout)super.getViewForListElement(paramLayoutInflater, paramContext, paramView);
    ImageView localImageView = (ImageView)localClickableRelativeLayout.findViewById(com.xynotec.gui.R.id.icon);
    
    ImageView arrow_next = (ImageView)localClickableRelativeLayout.findViewById(com.xynotec.gui.R.id.accessory);    
    arrow_next.setVisibility(View.VISIBLE);
    
    if (getImageId() != 0)
    {
      int i = getImageId();
      localImageView.setImageResource(i);
    }
    return localClickableRelativeLayout;
  }

  public void setImageId(int paramInt)
  {
    this.imageId = paramInt;
  }
}