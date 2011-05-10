package com.xynotec.gui.listview;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;

import java.util.ArrayList;
import java.util.List;

import com.xynotec.gui.listview.BaseListItem;
import com.xynotec.gui.listview.BoldLinkItem;
import com.xynotec.gui.listview.EmptyDivider;
import com.xynotec.gui.listview.IconLinkItem;
import com.xynotec.gui.listview.LabelTextItem;
import com.xynotec.gui.listview.LinkItem;
import com.xynotec.gui.listview.SectionHeader;
import com.xynotec.gui.listview.ThickDivider;
import com.xynotec.gui.listview.ThinDivider;


public class BaseListItemAdapter extends BaseAdapter
{
	public BaseListItemAdapter(Context context1)
    {
        context = context1;
        viewInflater = (LayoutInflater)getContext().getSystemService(android.content.Context.LAYOUT_INFLATER_SERVICE);        
        resultList = new ArrayList();
        
    }

    public void addAllToList(List list)
    {
        if(list != null)
            resultList.addAll(list);
    }

    public void addBrowseItemToList(int i, int j, Class class1)
    {
        LinkItem linkitem = buildBrowseItem(i, j, class1);
        addToList(linkitem);
        addThinDivider();
    }

    public LabelTextItem addLabelItemToList(int i, String s)
    {
        Object obj;
        if(i > 0 && s != null)
        {
            obj = getString(i);
            LabelTextItem labeltextitem = new LabelTextItem(((String) (obj)), s);
            addToList(labeltextitem);
            obj = labeltextitem;
        } else
        {
            obj = 0;
        }
        return ((LabelTextItem) (obj));
    }

    public LinkItem addLinkItemToList(int i, android.view.View.OnClickListener onclicklistener)
    {
        String s = getString(i);
        BoldLinkItem boldlinkitem = new BoldLinkItem(s, null, onclicklistener);
        addToList(boldlinkitem);
        return boldlinkitem;
    }

    public void addSectionHeader(int i)
    {
        String s = getString(i);
        addSectionHeader(s);
    }

    public void addSectionHeader(String s)
    {
        SectionHeader sectionheader = new SectionHeader(s);
        addToList(sectionheader);
    }

    public void addSpacer()
    {
    	EmptyDivider emptydivider = new EmptyDivider();
        addToList(emptydivider);        
    }

    public void addThickDivider()
    {
    	ThickDivider thickdivider = new ThickDivider();
        addToList(thickdivider);        
    }

    public void addThinDivider()
    {
    	ThinDivider thindivider = new ThinDivider();    	
        addToList(thindivider);

    }

    public void addToList(BaseListItem BaseListItem)
    {
        if(BaseListItem != null)
            resultList.add(BaseListItem);
    }

    public boolean areAllItemsEnabled()
    {
        return true;
    }

    public LinkItem buildBrowseItem(int i, int j, final Class class1)
    {
    	IconLinkItem iconlinkitem = new IconLinkItem();
        Context context1 = getContext();
        String s = context1.getString(i);
        iconlinkitem.setText(s);
        iconlinkitem.setImageId(j);
        BaseListItemAdapterClick click = new BaseListItemAdapterClick(context1, class1);
        iconlinkitem.setClickAction(click);
        /*
        iconlinkitem.setClickAction(new View.OnClickListener()
		{			
			@Override
			public void onClick(View v)
			{
				// TODO Auto-generated method stub
			    Context localContext1 = context;
			    Context localContext2 = context;
			    //Class localClass = context.getClass();
			    //final Class localClass = class1;
			    Intent localIntent = new Intent(localContext2, class1);
			    localContext1.startActivity(localIntent);
			}
		});
        */
		
        return iconlinkitem;        
    }

    protected Context getContext()
    {
        return context;
    }

    public int getCount()
    {
        return resultList.size();
    }

    public Object getItem(int i)
    {
        return resultList.get(i);
    }

    public long getItemId(int i)
    {
        return (long)i;
    }

    /*
    public int getItemViewType(int i)
    {
        Integer integer = Integer.valueOf(((BaseListItem)resultList.get(i)).getListElementLayoutId());
        int j = integer.intValue();
        if(j > 0)
            j = ((Integer)buildResultListTypeIndex().get(integer)).intValue();
        else
            j = -1;
        return j;
    }
    */

    protected String getString(int i)
    {
        return getContext().getString(i);
    }

    protected String getString(int i, Object aobj[])
    {
        return getContext().getString(i, aobj);
    }

    public View getView(int i, View view, ViewGroup viewgroup)
    {
        BaseListItem baseListItem = (BaseListItem)resultList.get(i);
        LayoutInflater layoutinflater = getViewInflater();
        Context context1 = getContext();
        return baseListItem.getViewForListElement(layoutinflater, context1, view);
    }

    protected LayoutInflater getViewInflater()
    {
        return viewInflater;
    }

    /*
    public int getViewTypeCount()
    {
        Collection collection = buildResultListTypeIndex().values();
        int j = collection.size();
        int i;
        if(j > 0)
            i = j;
        else
            i = 1;
        return i;
    }
    */

    public void insertAtIndex(BaseListItem BaseListItem, int i)
    {
        if(BaseListItem != null && resultList.size() > i)
            resultList.add(i, BaseListItem);
    }

    public boolean isEnabled(int i)
    {
        return ((BaseListItem)resultList.get(i)).isListElementClickable();
    }

    private Context context;
    protected List resultList;
    private LayoutInflater viewInflater;
    
    
    class BaseListItemAdapterClick implements View.OnClickListener
    {
    	Context m_Context;
    	Class mClass;
    	public BaseListItemAdapterClick(Context paramContext, Class paramClass)
    	{
    		m_Context = paramContext;
    		mClass = paramClass;    		
    	}
    	
	    public void onClick(View paramView)
	    {
	    	/*
	    	if (mClass == SearchItem.class)
	    	{
	    		SearchItemForm(mClass);
	    	}
	    	else if (mClass == SearchTextItem.class)
	    	{
	    		SearchTextItemForm(mClass);
	    	}	    
	    	else
	    	{
		    	Intent localIntent = new Intent(m_Context, mClass);
		    	m_Context.startActivity(localIntent);	    		
	    	}	
	    	*/
	    }
	    
	    public void SearchItemForm(final Class className)
	    {
 	
	    }
	    
	    public void SearchTextItemForm(final Class className)
	    {
	    	
	    }
    }
}