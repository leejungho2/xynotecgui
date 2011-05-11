
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

    protected abstract void applyToView(Context context, ClickableRelativeLayout clickablerelativelayout);

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
        
        applyToView(paramContext, clickablerelativelayout);
        return clickablerelativelayout;
    }

}