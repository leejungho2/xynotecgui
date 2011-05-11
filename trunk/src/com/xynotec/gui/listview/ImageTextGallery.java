package com.xynotec.gui.listview;

import android.content.Context;
import android.content.Intent;
import android.view.View;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;

public class ImageTextGallery extends AsyncPosterGallery
{
  public ImageTextGallery(Context paramContext)
  {
    super(paramContext);
    ImageTextGalleryClick local1 = new ImageTextGalleryClick(this);
    setOnClickListener(local1);
    CreateGalleryTest();
  }

  public void CreateGalleryTest()
  {
	  Context localContext = getContext();
	  BaseListItemAdapter localIMDbListAdapter = new BaseListItemAdapter(localContext);
	  
	  for(int i = 0; i < 10; i++)
	  {
		  AsyncPosterGallery.ImageTextItem localBigPosterTitleItem = new AsyncPosterGallery.ImageTextItem();
		  localBigPosterTitleItem.setImage(0);
		  localBigPosterTitleItem.setText("Item: #" + i);
		  
		  localIMDbListAdapter.addToList(localBigPosterTitleItem);
	  }
	  
	  setAdapter(localIMDbListAdapter);	    
	  
  }

 
  	class ImageTextGalleryClick implements View.OnClickListener
	{
	
	  public void onClick(View view)
	  {
		  /*
		  Context context = paramMovieMeterGallery.getContext();
	      Intent intent = new Intent(context, MoviesMeter.class);
	      context.startActivity(intent);
	      */
	  }
	
	  final ImageTextGallery paramMovieMeterGallery;
	
	  ImageTextGalleryClick(ImageTextGallery param)
	  {
		  paramMovieMeterGallery = param;      
	  }
	}
}
