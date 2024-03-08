package models
{
	//creating the start game menu for our game
	
	import controller.IState;
	
	import objects.Background;
	
	import starling.display.Button;
	import starling.display.Image;
	import starling.display.Sprite;
	import starling.events.Event;
	
	import views.Assets;
	import views.Game;
	/**
	 * Game Menu state
	 * @author Peter Shodeinde
	 * 
	 * */
	
	public class StartMenu extends Sprite implements IState
	{
		
		private var	game:Game;
		private var background:Background;
		private var logo:Image;
		private var startButton:Button;
		
		
		public function StartMenu(game:Game)
		{
			
			this.game = game;
			addEventListener(Event.ADDED_TO_STAGE, init)
		}
		// initizing the start menu state 
		private function init(event:Event):void
		{
			background = new Background();
			addChild(background);
			// logo creation
			logo = new Image(Assets.ta.getTexture("logoOne"));
			logo.pivotX = logo.width * 0.5;   //set the point.
			logo.x = 400;
			logo.y = 200;
			addChild(logo);
			startButton = new Button(Assets.ta.getTexture("startGameButton"));
			startButton.addEventListener(Event.TRIGGERED, playButton);
			startButton.pivotX = startButton.width * 0.5;
			startButton.x = 400;
			startButton.y = 450;
			addChild(startButton)
			
		}
		// play button function
		
		public function playButton(event:Event):void
		{
			game.changeState(Game.PLAYING_GAME_MODEL);
		}
		
		public function update():void
		{
			background.update();
		}
		/*	
		 *	memory uptimizing to avoid take up memory 
		*/
			
		public function destroy():void
		{

			background.removeFromParent(true);
			background = null;
			logo.removeFromParent(true);
			logo = null;
			startButton.removeFromParent(true);
			startButton = null;
			removeFromParent(true);
		}
	}
}