package com.github.weekings.model;

import java.util.List;

/**
 * 
 * An Event class represents an activity that takes place in a
 * certain period of time for a set amounts of time. Each activity
 * has a name a description and a list of EvenInstances.
 * 
 * @author Issle
 *
 */
public class Event {

	private String name;
	private String description;
	private List<EventInstance> instances;
	
	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getDescription() {
		return description;
	}

	public void setDescription(String description) {
		this.description = description;
	}

	public List<EventInstance> getInstances() {
		return instances;
	}

	public void setInstances(List<EventInstance> instances) {
		this.instances = instances;
	}
	
}
