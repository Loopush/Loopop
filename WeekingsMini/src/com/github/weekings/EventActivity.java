package com.github.weekings;

import java.util.List;

import com.github.weekings.model.Event;
import com.github.weekings.service.ServiceManager;

import android.app.Activity;
import android.os.Bundle;
import android.widget.TextView;

public class EventActivity extends Activity {
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
    	ServiceManager.getInstance().init();
        super.onCreate(savedInstanceState);
        setContentView(R.layout.eventactivity);
        
       TextView eventName = (TextView)findViewById(R.id.EventName);
       
       TextView eventDescription = (TextView)findViewById(R.id.EventDescription);
       
       List<Event> events = ServiceManager.getInstance().getEventService().getUpdatedEvents();
       
       Event e = events.get(0);
      
       eventName.setText(e.getName());
       eventDescription.setText(e.getDescription());
    }
}