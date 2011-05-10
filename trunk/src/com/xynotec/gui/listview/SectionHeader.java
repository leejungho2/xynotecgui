package com.xynotec.gui.listview;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.FrameLayout;
import android.widget.TextView;

import com.xynotec.gui.R;

public class SectionHeader
    implements BaseListItem
{

    public SectionHeader()
    {
    }

    public SectionHeader(String s)
    {
        text = s;
    }

    public int getListElementLayoutId()
    {
        return R.layout.list_header;
    }

    public String getText()
    {
        return text;
    }

    public View getViewForListElement(LayoutInflater layoutinflater, Context context, View view)
    {
        FrameLayout framelayout = null;
        TextView textview;
        String s;
        if(view == null)
        {
            int i = getListElementLayoutId();
            framelayout = (FrameLayout)layoutinflater.inflate(i, null);
        } 
        else
        {
            framelayout = (FrameLayout)view;
        }
        textview = (TextView)framelayout.findViewById(R.id.list_header_title);
        s = getText();
        textview.setText(s);
        return framelayout;
    }

    public boolean isListElementClickable()
    {
        return false;
    }

    public void setText(String s)
    {
        text = s;
    }

    private String text;
}