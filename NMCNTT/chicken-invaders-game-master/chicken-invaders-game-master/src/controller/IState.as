package controller
{
	
	/**
	 * Creating an interface for the two interfaces in the game context
	 * @author Peter Shodeinde
	 * 
	 * */
	public interface IState
	{
		//Update state 
		function update():void;
		//destroy state
		function destroy():void;
			
		
	}
}