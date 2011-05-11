package com.xynotec.gui;

import com.xynotec.gui.listview.AbstractExListActivity;
import com.xynotec.gui.listview.BaseListItemAdapter;
import com.xynotec.gui.listview.BoldLinkItem;
import com.xynotec.gui.listview.EmptyDivider;
import com.xynotec.gui.listview.HeaderLinkItem;
import com.xynotec.gui.listview.IconLinkItem;
import com.xynotec.gui.listview.LabelTextItem;
import com.xynotec.gui.listview.LinkItem;
import com.xynotec.gui.listview.SectionHeader;
import com.xynotec.gui.listview.ThickDivider;
import com.xynotec.gui.listview.ThinDivider;

import android.app.Activity;
import android.content.Context;
import android.os.Bundle;

public class FirstGui extends AbstractExListActivity {
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        
        HomeListAdapter localHomeListAdapter = new HomeListAdapter(FirstGui.this);
        
        BoldLinkItem blItem = new BoldLinkItem("BoldLinkItem", "BoldLinkItemEx", null);
        EmptyDivider eDiv = new EmptyDivider();  
        HeaderLinkItem hlItem = new HeaderLinkItem();
        IconLinkItem ilItem = new IconLinkItem(R.drawable.chevron_icon, "IconLinkItemEx", null);
        LabelTextItem ltItem = new LabelTextItem("LabelTextItem", "LabelTextItemEx");
        LinkItem lItem = new LinkItem("LinkItem", null);
        SectionHeader sHeader = new SectionHeader("SectionHeader");
        ThickDivider thickDiv = new ThickDivider();
        ThinDivider thinDiv = new ThinDivider();
        
        localHomeListAdapter.addToList(blItem);
        localHomeListAdapter.addToList(eDiv);
        localHomeListAdapter.addToList(hlItem);
        localHomeListAdapter.addToList(ilItem);
        localHomeListAdapter.addToList(ltItem);
        localHomeListAdapter.addToList(lItem);
        localHomeListAdapter.addToList(sHeader);
        localHomeListAdapter.addToList(thickDiv);
        localHomeListAdapter.addToList(thinDiv);
        
        setListAdapter(localHomeListAdapter);
        
    }
    
    public int getLayoutType()
    {
        return R.layout.main;
    }
    
    public class HomeListAdapter extends BaseListItemAdapter
    {
      public HomeListAdapter(Context context)
      {
        super(context);
      }

      public boolean areAllItemsEnabled()
      {
        return false;
      }
    }
}