package com.xynotec.gui.listview;

import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;

public abstract interface ExActivity
{
  public abstract int getLayoutType();

  public abstract String getPageTitle();

  public abstract boolean onCreateOptionsMenu(Menu paramMenu);

  public abstract boolean onOptionsItemSelected(MenuItem paramMenuItem);

  public abstract void prepareWindowAndContentView(Bundle paramBundle);
}
