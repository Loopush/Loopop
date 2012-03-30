package com.github.weekings.service.impl;

import java.util.logging.Level;
import java.util.logging.Logger;

import com.github.weekings.service.ILoggerService;
import com.github.weekings.service.IService;

public class LoggerService implements IService,ILoggerService{

	private static final Logger log = Logger.getLogger(LoggerService.class.getName());
	
	private static final String noClass = "No Class";
	
	
	public void log(Class<?> clazz, String message)
	{
		String className = noClass;
		
		if(clazz != null)
			className = clazz.getName();
		
		log.log(Level.INFO, className+": "+ message);
	}


	public void initialize() {
		// TODO Auto-generated method stub
		
	}


	public void shutdown() {
		// TODO Auto-generated method stub
		
	}

}
