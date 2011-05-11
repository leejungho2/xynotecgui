
package com.xynotec.gui.listview;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;
import java.util.Map;

// Referenced classes of package com.imdb.mobile.domain:
//            IMDbListElement

public abstract class AbstractConstItem implements BaseListItem
{
    public AbstractConstItem()
    {
        
    }

    public abstract int getListElementLayoutId();
  
    public boolean isListElementClickable()
    {
        return true;
    }

    public void setImage(ClickableRelativeLayout clickablerelativelayout)
    {
    	ImageView localImageView = (ImageView)clickablerelativelayout.findViewById(com.xynotec.gui.R.id.image);
    	if (localImageView != null)
    		localImageView.setImageResource(com.xynotec.gui.R.drawable.image_gallery);
    }

    public void setText(String s, ClickableRelativeLayout clickablerelativelayout)
    {
        TextView textview = (TextView)clickablerelativelayout.findViewById(com.xynotec.gui.R.id.text);
        if(textview != null)
        {
            if(s != null)
            {
                textview.setText(s);
                textview.setVisibility(View.VISIBLE);
            } else
            {
                textview.setVisibility(View.GONE);
            }
        }
    }

    @Override
    public View getViewForListElement(LayoutInflater paramLayoutInflater,
    		Context paramContext, View paramView)
    {
    	// TODO Auto-generated method stub
        ClickableRelativeLayout clickablerelativelayout;
        if(paramView == null)
        {
            int id = getListElementLayoutId();
            clickablerelativelayout = (ClickableRelativeLayout)paramLayoutInflater.inflate(id, null);
        } 
        else
        {
            clickablerelativelayout = (ClickableRelativeLayout)paramView;
        }
        return clickablerelativelayout;
    }

}