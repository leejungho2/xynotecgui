package com.xynotec.gui.listview;

import android.content.Context;
import android.view.View;
import android.widget.HorizontalScrollView;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.TextView;

public abstract class AsyncPosterGallery extends HorizontalScrollView
  //implements ClientDelegate
{
  protected static final int defaultInitialPostersToLoad = 7;
  protected static final int maxPostersToShow = 25;
  protected static final int posterHeight = 140;
  protected static final int posterWidth = 90;
  private LinearLayout container;
  protected BaseListItemAdapter galleryAdapter;
  private int posterItemsDisplayed = 0;
  private int postersToShow;

  public AsyncPosterGallery(Context paramContext)
  {
    super(paramContext);
    initializeGallery();
  }

  protected void initializeGallery()
  {	  
	  
  }

  /*
  	@Override
	protected void onScrollChanged(int l, int t, int oldl, int oldt)
	{
		// TODO Auto-generated method stub
		super.onScrollChanged(l, t, oldl, oldt);
	}
  	*/
  	
  
  protected void onScrollChanged(int paramInt1, int paramInt2, int paramInt3, int paramInt4)
  {
    super.onScrollChanged(paramInt1, paramInt2, paramInt3, paramInt4);
    int i = this.posterItemsDisplayed;
    int j = this.postersToShow;
    if ((i >= j) || (this.galleryAdapter == null))
      return;
    int k = this.postersToShow;
    if (getWidth() > 0)
    {
      k = (getWidth() + paramInt1) / 90 + 1;
      int l = this.postersToShow;
      if (k > l)
        k = this.postersToShow;
    }
    int i1 = this.posterItemsDisplayed;
    if (k <= i1)
      return;
    for (int i2 = this.posterItemsDisplayed; i2 < k; ++i2)
    {
      BaseListItemAdapter localIMDbListAdapter = this.galleryAdapter;
      LinearLayout localLinearLayout = this.container;
      View localView = localIMDbListAdapter.getView(i2, null, localLinearLayout);
      View.OnClickListener localOnClickListener = ((ClickableRelativeLayout)localView).getViewOnClickAction();
      localView.setOnClickListener(localOnClickListener);
      this.container.removeViewAt(i2);
      this.container.addView(localView, i2);
      int i3 = this.posterItemsDisplayed;
      i3++;
      this.posterItemsDisplayed = i3;
    }   
  }
   	
  protected void setAdapter(BaseListItemAdapter var1) {
      byte var2 = 25;
      this.galleryAdapter = var1;
      Context var3 = this.getContext();
      LinearLayout var4 = new LinearLayout(var3);
      this.container = var4;
      this.container.setPadding(10, 0, 20, 0);
      int var20 = var1.getCount();
      if(var20 > var2) {
         var20 = var2;
      } else {
         var20 = var1.getCount();
      }

      this.postersToShow = var20;
      int var5 = this.postersToShow * 90;
      LinearLayout var6 = this.container;
      android.widget.LinearLayout.LayoutParams var7 = new android.widget.LinearLayout.LayoutParams(var5, -1);
      //((LinearLayout)(Object)var20).setLayoutParams(var7);
      var4.setLayoutParams(var7);
      int var8;
      if(this.getWidth() > 0) {
         var8 = this.getWidth() / 90 + 1;
      } else {
         var8 = 7;
      }

      int var9 = this.postersToShow;
      if(var8 > var9) {
         var8 = this.postersToShow;
      }

      int var10 = 0;

      while(true) {
         int var11 = this.postersToShow;
         if(var10 >= var11) {
            this.removeAllViews();
            LinearLayout var19 = this.container;
            this.addView(var19);
            return;
         }

         if(var10 < var8) {
            LinearLayout var12 = this.container;
            View var13 = var1.getView(var10, (View)null, var12);
            OnClickListener var14 = ((ClickableRelativeLayout)var13).getViewOnClickAction();
            var13.setOnClickListener(var14);
            this.container.addView(var13);
            int var15 = this.posterItemsDisplayed;
            ++var20;
            this.posterItemsDisplayed = var15;
         } else {
            Context var16 = this.getContext();
            View var17 = new View(var16);
            android.widget.LinearLayout.LayoutParams var18 = new android.widget.LinearLayout.LayoutParams(90, 140);
            var17.setLayoutParams(var18);
            this.container.addView(var17);
         }

         ++var10;
      }
   }

  public class ImageTextItem extends AbstractConstItem
  {
    public ImageTextItem()
    {
      super();
    }
    
    int imageId;
    String text;
    
    public void setText(String s)
    {
    	text = s;    	
    }
    
    public void setImage(int resId)
    {
    	imageId = resId;
    }

    public int getListElementLayoutId()
    {
      return com.xynotec.gui.R.layout.image_text_gallery_item;
    } 
    
    protected void applyToView(Context context, ClickableRelativeLayout clickablerelativelayout)
    {
    	setImage(clickablerelativelayout);
    	setText(clickablerelativelayout);
    }
    
    
    protected void setImage(ClickableRelativeLayout clickablerelativelayout)
    {
    	ImageView localImageView = (ImageView)clickablerelativelayout.findViewById(com.xynotec.gui.R.id.image);
    	if (localImageView != null)
    		localImageView.setImageResource(com.xynotec.gui.R.drawable.image_gallery);
    }

    protected void setText(ClickableRelativeLayout clickablerelativelayout)
    {
        TextView textview = (TextView)clickablerelativelayout.findViewById(com.xynotec.gui.R.id.text);
        if(textview != null)
        {
            if(text != null)
            {
                textview.setText(text);
                textview.setVisibility(View.VISIBLE);
            } else
            {
                textview.setVisibility(View.GONE);
            }
        }
    }
  }
  
}