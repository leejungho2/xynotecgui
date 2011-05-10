package com.xynotec.gui.listview;

import android.app.Activity;
import android.app.SearchManager;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.view.Window;
import android.widget.ImageView;
import android.widget.TextView;

public class MixExActivity
  implements ExActivity
{
  private Activity activity;

  MixExActivity(Activity paramActivity)
  {
    this.activity = paramActivity;
  }

  public int getLayoutType()
  {
    return ((ExActivity)this.activity).getLayoutType();
  }

  public String getPageTitle()
  {
    return ((ExActivity)this.activity).getPageTitle();
  }

  public boolean onCreateOptionsMenu(Menu paramMenu)
  {
    return true;
  }

  public boolean onOptionsItemSelected(MenuItem paramMenuItem)
  {
	  return false;
  }

  public void prepareWindowAndContentView(Bundle paramBundle)
  {
	  /*
      activity.requestWindowFeature(Window.FEATURE_CUSTOM_TITLE);
      Activity activity1 = activity;
      int i = ((ExActivity)activity).getLayoutType();
      activity1.setContentView(i);
      
      activity.getWindow().setFeatureInt(Window.FEATURE_CUSTOM_TITLE, com.siglaz.customctrl.R.layout.default_titlebar);
      String str = ((ExActivity)activity).getPageTitle();
      setTitlebarText(str);
      */

    
  }

  public void setTitlebarText(String paramString)
  {
	  /*
    if (paramString == null)
      return;
    ((TextView)this.activity.findViewById(com.siglaz.customctrl.R.id.title_bar_text)).setText(paramString);
    */
  }
  
  
  class MixExActivityClick implements View.OnClickListener
  {
	  Activity mActivity;
	  public MixExActivityClick(Activity activity)
	  {
		  mActivity = activity;
	  }
	  public void onClick(View paramView)
	  {
		  /*
	    Intent localIntent = new Intent(mActivity, MainList.class);
	    mActivity.startActivity(localIntent);
	    */
	  }
	}
}