package com.github.weekings.service;

public interface ILoggerService 
{
	/**
	 * Logs information from the given class.
	 * @param clazz
	 * @param message
	 */
	public void log(Class<?> clazz, String message);
}
