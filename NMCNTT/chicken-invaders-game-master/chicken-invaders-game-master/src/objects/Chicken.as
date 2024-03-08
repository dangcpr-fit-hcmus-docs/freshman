package objects
{
	import views.Assets;
	import starling.display.MovieClip;
	import starling.textures.Texture;
	/**
	 * Creating the chicken object from the asset file.
	 * @author Peter Shodeinde
	 * 
	 * */
	public class Chicken extends MovieClip
	{
		public function Chicken()
		{
			super(Assets.ta.getTextures("chicken_red"), 12);
			pivotX = width * 0.5;
			pivotY = height * 0.5;
		}
	}
}