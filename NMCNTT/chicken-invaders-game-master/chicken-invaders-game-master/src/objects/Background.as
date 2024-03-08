package objects
{
	import starling.display.Image;
	import starling.display.Sprite;
	
	import views.Assets;
	/**
	 * Creating the downward movement of the background for the game
	 * @author Peter Shodeinde
	 * 
	 * */
	public class Background extends Sprite
	{
		private var background1:Image;
		private var background2:Image;
		public function Background()
		{
			//for the scrolling effect, we create two instance variable and align the position of one over the other
			background1 = new Image(Assets.backgroundTexture);
			addChild(background1);
			
			background2 = new Image(Assets.backgroundTexture);
			background2.y = -800; // to position it above background 1
			addChild(background2);
			
			
			
		}
		
		//update the position, and handle the movement of the background
		public function update():void
		{
			background1.y += 4;
			if(background1.y == 800){
				background1.y = -800
			}
			background2.y += 4;
			if(background2.y == 800){
				background2.y = -800;
			}
				
		}
	}
}