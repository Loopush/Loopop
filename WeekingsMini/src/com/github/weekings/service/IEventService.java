package com.github.weekings.service;

import java.util.List;

import com.github.weekings.model.Event;

public interface IEventService {
	
	/**
	 * Returns the updated versions of the events that this user listens to.
	 * @return
	 */
	public List<Event> getUpdatedEvents();
	
	/**
	 * Returns all the events that the user has registered to.
	 * @return
	 */
	public List<Event> getRegisteredEvents();
	
	/**
	 * Registers this user to the specified event.
	 * @param e
	 * @return
	 */
	public void registerAtEvent(Event e);
	
	/**
	 * Removes the given event from the user's list.
	 * @param e
	 * @return
	 */
	public void unregisterFromEvent(Event e);
	

}
