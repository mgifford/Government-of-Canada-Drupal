/*!
 * Charts and graphs support v1.01 / Soutien des graphiques v1.01
 * Web Experience Toolkit (WET) / Boîte à outils de l'expérience Web (BOEW)
 * Terms and conditions of use: http://tbs-sct.ircan.gc.ca/projects/gcwwwtemplates/wiki/Terms
 * Conditions régissant l'utilisation : http://tbs-sct.ircan.gc.ca/projects/gcwwwtemplates/wiki/Conditions
 */
(function ($) {
var charts = {
	
	// Load the parameters used in the plugin declaration. Parameters can be access using this.parms.parameterName
	params :  Utils.loadParamsFromScriptID("charts"),
	
	//Used to store localized strings for your plugin.
	/*dictionary : {
	        myString1 :(PE.language == "eng") ? "String 1:" : "Chaine 1 :",
	        myString2 :(PE.language == "eng") ? "String 2" : "Chaine 2"
	},*/
	
	//Method that is executed when the page loads
	init : function(){
		//Loads the style for the chart
		var style = (this.params.style != null) ? this.params.style : 'light';
		Utils.addCSSSupportFile(Utils.getSupportPath()+"/charts/style-" + style + ".css"); 
		
		var paramsFix = eval(decodeURIComponent(this.params.chart));
		
		$(paramsFix).each(function(index, value){
			var graph = $(value.selector).visualize({type : value.type}, (value.container != null) ? $(value.container) : null)
		});
	}
}
// Add Style Sheet Support for this plug-in
Utils.addCSSSupportFile(Utils.getSupportPath()+"/charts/style.css"); 


//Loads a library that the plugin depends on from the lib folder
PE.load('excanvas.js');
PE.load('visualize.jQuery.js');
//PE.load('example.js');

// Init Call at Runtime
$("document").ready(function(){   charts.init(); });
})(jQuery);