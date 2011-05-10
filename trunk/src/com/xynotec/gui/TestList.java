package com.siglaz.customctrl.listview;

import android.app.ProgressDialog;
import android.content.Context;

import com.siglaz.customctrl.R;

import android.os.Bundle;
import android.view.View;
import android.content.Intent;

import com.siglaz.customctrl.commonctrl.LoadingDialog;
import com.siglaz.customctrl.commonctrl.ProcessResultListRunnable;
import com.siglaz.customctrl.data.WineData;
import com.siglaz.customctrl.myview.*;

public class MainList extends AbstractExListActivity
{
	public String getPageTitle()
	{
		return getString(com.siglaz.customctrl.R.string.app_name);
	}

	@Override
	public void onCreate(Bundle paramBundle) 
	{
		// TODO Auto-generated method stub
		super.onCreate(paramBundle);
		setContentView(R.layout.home);
		
		final ProgressDialog progressDialog = new LoadingDialog(this);
		
		progressDialog.show();
		
		final Runnable fillList = new Runnable() 
		{

			@Override
			public void run() 
			{
				WineData.GetWine10();
				
				WineData.GetWineType();
				WineData.GetPriceRange();

				HomeListAdapter localHomeListAdapter = new HomeListAdapter(MainList.this);
				localHomeListAdapter.addSmallBrowseItem(com.siglaz.customctrl.R.string.topTenWine, WineTop10.class);

				ItemPosterGalley itemPosterList = new ItemPosterGalley(MainList.this);
				localHomeListAdapter.addToList(itemPosterList);				

				localHomeListAdapter.addSectionHeader("Wines");
				
				localHomeListAdapter.addBrowseItemToList(com.siglaz.customctrl.R.string.searchItem, com.siglaz.customctrl.R.drawable.search_by, SearchItem.class);
				localHomeListAdapter.addBrowseItemToList(com.siglaz.customctrl.R.string.searchTextItem, com.siglaz.customctrl.R.drawable.search_text, SearchTextItem.class);
				localHomeListAdapter.addBrowseItemToList(com.siglaz.customctrl.R.string.top100Wine, com.siglaz.customctrl.R.drawable.top100, WineTop100.class);
				
				runOnUiThread(new ProcessResultListRunnable(MainList.this, localHomeListAdapter, progressDialog));
			}
		};

		new Thread(fillList).start();		

		/*
		setContentView(R.layout.home);	

		HomeListAdapter localHomeListAdapter = new HomeListAdapter(this);
		localHomeListAdapter.addSmallBrowseItem(com.siglaz.customctrl.R.string.topTenWine, MoviesMeter.class);

		ItemPosterGalley itemPosterList = new ItemPosterGalley(this);
		localHomeListAdapter.addToList(itemPosterList);
		
		//TitlePageSummaryItem titlePageSummaryItem= new TitlePageSummaryItem(null, localHomeListAdapter);
		//localHomeListAdapter.addToList(titlePageSummaryItem);
		
		//TitleStarRatingItem titleStarRatingItem= new TitleStarRatingItem(null, localHomeListAdapter);
		//localHomeListAdapter.addToList(titleStarRatingItem);		

		localHomeListAdapter.addSectionHeader("Wines");
		
		localHomeListAdapter.addBrowseItemToList(com.siglaz.customctrl.R.string.searchItem, com.siglaz.customctrl.R.drawable.film_home_icon, SearchItem.class);
		localHomeListAdapter.addBrowseItemToList(com.siglaz.customctrl.R.string.searchTextItem, com.siglaz.customctrl.R.drawable.film_home_icon, SearchTextItem.class);
		localHomeListAdapter.addBrowseItemToList(com.siglaz.customctrl.R.string.top100Wine, com.siglaz.customctrl.R.drawable.film_home_icon, MoviesTop250.class);
		//localHomeListAdapter.addBrowseItemToList(com.siglaz.customctrl.R.string.Home_label_top250movies, com.siglaz.customctrl.R.drawable.film_home_icon, MoviesTop250.class);

		setListAdapter(localHomeListAdapter);
		*/
	}
	
    public int getLayoutType()
    {
        return com.siglaz.customctrl.R.layout.home;
    }
    
    public class HomeListAdapter extends BaseListItemAdapter
    {
      public HomeListAdapter(Context context)
      {
        super(context);
      }

      public void addSmallBrowseItem(int paramInt,final Class paramClass)
      {
        HeaderLinkItem localHeaderLinkItem = new HeaderLinkItem();
        final Context localContext = getContext();
        String str = localContext.getString(paramInt);
        localHeaderLinkItem.setText(str);
        localHeaderLinkItem.setClickAction(new View.OnClickListener()
        {
        	public void onClick(View paramView)
        	  {
        		Intent localIntent = new Intent(localContext, paramClass);
        		localContext.startActivity(localIntent);
        		//Context localContext1 = localContext;
        	    //Context localContext2 = localContext;
        	    //Class localClass = paramClass;
        	    //Intent localIntent = new Intent(localContext2, localClass);
        	    //localContext1.startActivity(localIntent);
        	    
        	  }        	
        });
        addToList(localHeaderLinkItem);
      }

      public boolean areAllItemsEnabled()
      {
        return false;
      }
    }
    
    public class ItemPosterGalley extends GenericViewItem
    {

        public View getView()
        {
            return new MovieMeterGallery(mainList);
        }

        final MainList mainList;

        ItemPosterGalley(MainList param)
        {
        	mainList = param;
            
        }
    }

}
