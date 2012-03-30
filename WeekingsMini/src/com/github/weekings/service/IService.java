package com.github.weekings.service;

/**
 * Each service must be initialized before the application loads
 * and must be finalized before the application shuts down.
 *
 * @author Issle
 *
 */
public interface IService {

	/**
	 * Initializes the service.
	 */
	public void initialize();
	
	/**
	 * Does the final work before the service exits.
	 */
	public void shutdown();
	
}
