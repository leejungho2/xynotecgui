package com.xynotec.gui.listview;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.TextView;
import android.widget.ImageView;
import com.xynotec.gui.R;

public class LabelTextItem  implements BaseListItem
{
  private View.OnClickListener clickAction;
  private String label;
  private String text;

  public LabelTextItem()
  {
  }

  public LabelTextItem(String labelStr, String textStr)
  {
    this.label = labelStr;
    this.text = textStr;
  }

  public static ClickableRelativeLayout createLabelListItemWithText(String labelStr, String textStr, View.OnClickListener paramOnClickListener, View paramView, LayoutInflater paramLayoutInflater)
  {
    ClickableRelativeLayout localClickableRelativeLayout = null;
    
    if (paramView == null)
    {
      localClickableRelativeLayout = (ClickableRelativeLayout)paramLayoutInflater.inflate(R.layout.label_list_item, null);
      TextView localLabel = (TextView)localClickableRelativeLayout.findViewById(R.id.label);
      TextView localText = (TextView)localClickableRelativeLayout.findViewById(R.id.text);
      
      if (localLabel != null)
      {
    	  localLabel.setText(labelStr);
    	  localLabel.setVisibility(View.VISIBLE);
      }
            
      if (localText != null)
      {
    	  localText.setText(textStr);
    	  localText.setVisibility(View.VISIBLE);
      }
          
      ImageView localImageView = (ImageView)localClickableRelativeLayout.findViewById(R.id.accessory);
      if (paramOnClickListener == null)
    	  localImageView.setVisibility(View.GONE);
      
      localClickableRelativeLayout.setViewOnClickAction(paramOnClickListener);
      localImageView.setVisibility(View.VISIBLE);
    }
    
    return localClickableRelativeLayout;
    
  }

  public View.OnClickListener getClickAction()
  {
    return this.clickAction;
  }

  public String getLabel()
  {
    return this.label;
  }

  public int getListElementLayoutId()
  {
    return R.layout.label_list_item;
  }

  public String getText()
  {
    return this.text;
  }

  public View getViewForListElement(LayoutInflater paramLayoutInflater, Context paramContext, View paramView)
  {
    String str1 = this.label;
    String str2 = this.text;
    View.OnClickListener localOnClickListener = this.clickAction;
    return createLabelListItemWithText(str1, str2, localOnClickListener, paramView, paramLayoutInflater);
  }

  public boolean isListElementClickable()
  {
    View.OnClickListener localOnClickListener = this.clickAction;
    
    if (localOnClickListener != null)
      return true;
    else
    	return false;
  }

  public void setClickAction(View.OnClickListener paramOnClickListener)
  {
    this.clickAction = paramOnClickListener;
  }

  public void setLabel(String paramString)
  {
    this.label = paramString;
  }

  public void setText(String paramString)
  {
    this.text = paramString;
  }
}
