package views
{
	import controller.IState;
	
	import models.*;
	
	import starling.display.Sprite;
	import starling.events.Event;
	/**
	 * 
	 * Initializing the game sections from the menu to the game over section
	 * @author Peter Shodeinde
	 * */
	//Initializing the game world in starling class
	public class Game extends Sprite
	{
		//Creating a constant for the 3 game model sections
		public static const MENU_MODEL:int = 0;
		public static const PLAYING_GAME_MODEL:int = 1;
		public static const GAME_OVER_MODEL:int = 2;
		
		//current state
		private var current_state:IState;
		public function Game()
			
		{
			//Loading the assets when the game states
			Assets.init();
			addEventListener(Event.ADDED_TO_STAGE, init);
		}
		
		private function init(event:Event):void
		{
			//Setting the initial state of the game to the menu state
			changeState(MENU_MODEL);
			addEventListener(Event.ENTER_FRAME, update);
		}
		
		
		//changing the state of the game
		public function changeState(state:int):void
		{
			//test if the current state of the game is null
			if(current_state != null){
				current_state.destroy();
				current_state = null;
			}
			//switching between the state to know the current position of the states
			switch(state)
			{
				case MENU_MODEL: current_state = new StartMenu(this);
					break;
				case PLAYING_GAME_MODEL: current_state = new PlayingGame(this);
					break;
				case GAME_OVER_MODEL: current_state = new GameOver(this);
					break;
				
			}
			addChild(Sprite(current_state));
		
		}
		private function update(event:Event):void
		{
			//to call the update method of the state
			current_state.update();
		}
	}
}