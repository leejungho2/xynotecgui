package com.xynotec.gui.listview;

import android.app.ListActivity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.ListAdapter;
import android.widget.ListView;

public abstract class AbstractExListActivity extends ListActivity
  implements ExActivity
{
  private MixExActivity mixin;

  public AbstractExListActivity()
  {
	  MixExActivity localIMDbActivityMixin = new MixExActivity(this);
      this.mixin = localIMDbActivityMixin;
  }

  public int getLayoutType()
  {
	  return com.xynotec.gui.R.layout.generic_text_list;

  }

  public String getPageTitle()
  {
    return null;
  }

  public void onCreate(Bundle paramBundle)
  {
    super.onCreate(paramBundle);
    prepareWindowAndContentView(paramBundle);
  }

  public boolean onCreateOptionsMenu(Menu paramMenu)
  {
    return this.mixin.onCreateOptionsMenu(paramMenu);
  }

  protected void onListItemClick(ListView listview, View view, int i, long l)
  {
      if(view instanceof ClickableItem)
      {
          android.view.View.OnClickListener onclicklistener = ((ClickableItem)view).getViewOnClickAction();
          if(onclicklistener != null)
              onclicklistener.onClick(view);
      } else
      {
          view.performClick();
      }
  }

  public boolean onOptionsItemSelected(MenuItem paramMenuItem)
  {
    return this.mixin.onOptionsItemSelected(paramMenuItem);
  }

  public void prepareWindowAndContentView(Bundle paramBundle)
  {
    this.mixin.prepareWindowAndContentView(paramBundle);
  }

  public void setListAdapter(ListAdapter paramListAdapter)
  {
    if (paramListAdapter instanceof BaseListItemAdapter)
    {
      AbstractExListActivity_1 local1 = new AbstractExListActivity_1(this);
      ((BaseListItemAdapter)paramListAdapter).insertAtIndex(local1, 0);
    }
    super.setListAdapter(paramListAdapter);
  }

  public void setTitlebarText(String paramString)
  {
    this.mixin.setTitlebarText(paramString);
  }
  
  class AbstractExListActivity_1 extends GenericViewItem
  {

      public View getView()
      {
          //AbstractExListActivity abstractimdblistactivity = AbstractExListActivity.this;
          //return new View(abstractimdblistactivity);
    	  return new View(aExListActivity);
      }

      public boolean isListElementClickable()
      {
          return false;
      }

      final AbstractExListActivity aExListActivity;

      AbstractExListActivity_1(AbstractExListActivity param)
      {
    	  aExListActivity = param;
          //super();
      }
  }
}

