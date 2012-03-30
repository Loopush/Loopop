package com.github.weekings.service;

import com.github.weekings.service.impl.EventService;
import com.github.weekings.service.impl.LoggerService;

public class ServiceManager {

	private IEventService eventService;
	private ILoggerService loggerService;

	public void init()
	{
		eventService = new EventService();
		loggerService = new LoggerService();
	}
	
	public IEventService getEventService() {
		return eventService;
	}

	public void setEventService(IEventService eventService) {
		this.eventService = eventService;
	}

	private ServiceManager() {
	}

	/**
	 * SingletonHolder is loaded on the first execution of
	 * Singleton.getInstance() or the first access to SingletonHolder.INSTANCE,
	 * not before.
	 */
	private static class SingletonHolder 
	{
		public static final ServiceManager instance = new ServiceManager();
	}

	public static ServiceManager getInstance() 
	{
		return SingletonHolder.instance;
	}

	public ILoggerService getLoggerService() {
		return loggerService;
	}

	public void setLoggerService(ILoggerService loggerService) {
		this.loggerService = loggerService;
	}

}
