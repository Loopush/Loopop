package com.github.weekings.service.impl;

import java.util.ArrayList;
import java.util.List;

import com.github.weekings.model.Event;
import com.github.weekings.model.EventInstance;
import com.github.weekings.service.IEventService;
import com.github.weekings.service.IService;

public class EventService implements IService, IEventService{

	public void shutdown() {
		// TODO Auto-generated method stub
		
	}
	
	public void initialize() {
		// TODO Auto-generated method stub
		
	}

	
	public List<Event> getUpdatedEvents()
	{
		Event e = new Event();
		
		e.setName("Loopush Meeting");
		e.setDescription("This is the loopush meeting.");
		
		EventInstance i1 = new EventInstance();
		
		EventInstance i2 = new EventInstance();
		
		List<EventInstance> list = new ArrayList<EventInstance>();
		
		list.add(i1);
		list.add(i2);
		
		e.setInstances(list);
		
		List<Event> events = new ArrayList<Event>();
		events.add(e);
		return events;
		
		
	}

	public List<Event> getRegisteredEvents() {
		// TODO Auto-generated method stub
		return null;
	}

	public void registerAtEvent(Event e) {
		// TODO Auto-generated method stub
		
	}

	public void unregisterFromEvent(Event e) {
		// TODO Auto-generated method stub
		
	}


}
