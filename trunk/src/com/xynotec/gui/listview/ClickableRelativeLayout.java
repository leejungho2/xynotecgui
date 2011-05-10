package com.xynotec.gui.listview;

import android.content.Context;
import android.graphics.Rect;
import android.util.AttributeSet;
import android.view.View;
import android.widget.RelativeLayout;

public class ClickableRelativeLayout extends RelativeLayout
  implements ClickableItem
{
  private View.OnClickListener viewOnClickListener;

  public ClickableRelativeLayout(Context paramContext)
  {
    super(paramContext);
  }

  public ClickableRelativeLayout(Context paramContext, AttributeSet paramAttributeSet)
  {
    super(paramContext, paramAttributeSet);
  }

  public ClickableRelativeLayout(Context paramContext, AttributeSet paramAttributeSet, int paramInt)
  {
    super(paramContext, paramAttributeSet, paramInt);
  }

  public View.OnClickListener getViewOnClickAction()
  {
    return this.viewOnClickListener;
  }

  protected void onFocusChanged(boolean paramBoolean, int paramInt, Rect paramRect)
  {
    super.onFocusChanged(paramBoolean, paramInt, paramRect);
  }

  public void setViewOnClickAction(View.OnClickListener paramOnClickListener)
  {
    this.viewOnClickListener = paramOnClickListener;
  }
}
