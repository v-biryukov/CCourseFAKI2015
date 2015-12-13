//-------8<-----------------8<---------------8<-------------8<---------------begin script code
/*
_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
_/_/														_/_/
_/_/	Script 4 N - el_books								_/_/
_/_/	author: Portnov Dmitri								_/_/
_/_/	date: 01.02.2oo3									_/_/
_/_/														_/_/
_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
*/
window.glavs = glavs;

function go2nextglav_(currglav,currpage,current_level)
{
	currglav++;
	if(currglav == window.glavs[current_level].length)
	{
		currglav--;
	}
	currpage=0;
	path = window.basefolder + window.glavs[current_level][currglav][currpage];
	if(window.glavs[current_level][currglav][currpage]==undefined){
		path = $(location).attr("href");
	}
	$("#fwdgl").attr("href",path);
	return true;
}
function go2nextpage_(currglav,currpage,current_level)
{
	currpage++;
	if (window.glavs[current_level][currglav][currpage]==null)
	{
		currpage=0;
		if(currglav == window.glavs[current_level].length-1)
		{
			currpage=window.glavs[current_level][currglav].length-1;
			path = window.basefolder + window.glavs[current_level][currglav][currpage];
			if(window.glavs[current_level][currglav][currpage]==undefined){
				path = $(location).attr("href");
			}
			$("#fwdpg").attr("href",path);
			return true;
		}
		currglav++;
		if(currglav == window.glavs[current_level].length)
		{
			currglav--;
		}
		currpage=0;
		path = window.basefolder + window.glavs[current_level][currglav][currpage];
		if(window.glavs[current_level][currglav][currpage]==undefined){
			path = $(location).attr("href");
		}
		$("#fwdpg").attr("href",path);
		return true;
	}
	else
	{
		path = window.basefolder + window.glavs[current_level][currglav][currpage];
		if(window.glavs[current_level][currglav][currpage]==undefined){
			path = $(location).attr("href");
		}
		$("#fwdpg").attr("href",path);
		return true;
	}
}
function go2prevglav_(currglav,currpage,current_level)
{
	currglav--;
	if(currglav==-1)
	{
		currglav++;
	}
	currpage=0;
	path = window.basefolder + window.glavs[current_level][currglav][currpage];
	$("#bckgl").attr("href",path);
	return true;
}
function go2prevpage_(currglav,currpage,current_level)
{
	currpage--;
	if (currpage==-1)
	{
		currglav--;
		if(currglav==-1)
		{
			currglav++;
			currpage++;
			path = window.basefolder + window.glavs[current_level][currglav][currpage];
			$("#bckpg").attr("href",path);
			return true;
		}
		else
		{
		currpage=window.glavs[current_level][currglav].length-1;
		path = window.basefolder + window.glavs[current_level][currglav][currpage];
		$("#bckpg").attr("href",path);
		return true;
		}
	}
	path = window.basefolder + window.glavs[current_level][currglav][currpage];
	$("#bckpg").attr("href",path);
	return true;
}

$(document).ready(function(){
	window.current_level = 0;
	var glavs = window.glavs;
	var curr_path = $(location).attr("href");
	var start = 0;
	var stop = curr_path.lastIndexOf(basefolder)+basefolder.length;	
	var unnecessary_symbols = stop - start;
	var curr_frame_path = document.location.href;
	var clean_curr_frame_path = curr_frame_path.substring(unnecessary_symbols,curr_frame_path.length);
	/*part1.html*/
	var ok = false;
	
	for(var current_level=0; current_level<level.length; ++current_level)
	{
		//alert(current_level);
		for(var i=0; i<glavs[current_level].length; ++i)
		{
			for(var j=0; j<glavs[current_level][i].length; ++j)
			{
				if(clean_curr_frame_path.length==glavs[current_level][i][j].length)
				{
					if(glavs[current_level][i][j]==clean_curr_frame_path)
					{
						currglav = i;
						currpage = j;
						ok = true;
						break;
					}
				}
				if(clean_curr_frame_path.length > glavs[current_level][i][j].length)
				{
					var temp = clean_curr_frame_path.substring(0,glavs[current_level][i][j].length);
					if(glavs[current_level][i][j]==temp)
					{
						currglav = i;
						currpage = j;
						ok = true;
						break;
					}
				}
				if(clean_curr_frame_path.length < glavs[current_level][i][j].length)
				{
					var temp = glavs[current_level][i][j].substring(0,clean_curr_frame_path.length);
					if(temp==clean_curr_frame_path)
					{
						currglav = i;
						currpage = j;
						ok = true;
						break;
					}
				}
			}
			if(ok)break;
		}
		if(ok)break;
	}

	window.current_level = current_level;	
	go2prevglav_(currglav,currpage,current_level);
	go2prevpage_(currglav,currpage,current_level);
	go2nextpage_(currglav,currpage,current_level);
	go2nextglav_(currglav,currpage,current_level);
	$("#navsel option").eq(current_level).attr("selected", "selected");
	

});



function calculate(key,glavs,cod,current_level)
{
	var curr_path = document.location.href;
	var start = 0;
	var stop = curr_path.lastIndexOf(basefolder)+basefolder.length;	
	var unnecessary_symbols = stop - start;
	var curr_frame_path = document.location.href;
	var clean_curr_frame_path = curr_frame_path.substring(unnecessary_symbols,curr_frame_path.length);
	/*part1.html*/
	var ok = false;
	for(var i=0; i<glavs[current_level].length; ++i)
	{
		for(var j=0; j<glavs[current_level][i].length; ++j)
		{
			if(clean_curr_frame_path.length==glavs[current_level][i][j].length)
			{
				if(glavs[current_level][i][j]==clean_curr_frame_path)
				{
					currglav = i;
					currpage = j;
					ok = true;
					break;
				}
			}
			if(clean_curr_frame_path.length > glavs[current_level][i][j].length)
			{
				var temp = clean_curr_frame_path.substring(0,glavs[current_level][i][j].length);
				if(glavs[current_level][i][j]==temp)
				{
					currglav = i;
					currpage = j;
					ok = true;
					break;
				}
			}
			if(clean_curr_frame_path.length < glavs[current_level][i][j].length)
			{
				var temp = glavs[current_level][i][j].substring(0,clean_curr_frame_path.length);
				if(temp==clean_curr_frame_path)
				{
					currglav = i;
					currpage = j;
					ok = true;
					break;
				}
			}
		}
		if(ok)break;
	}

//alert(clean_curr_frame_path+" "+currglav+" "+currpage);

/////////////////////////////////new idea///////////////////////////////////////
//	currglav = parseInt(cod.substring(0,cod.lastIndexOf('_')).charAt(0),10);
//	currpage = parseInt(cod.substring(cod.lastIndexOf('_')+1).charAt(0),10);
	switch(key)
		{
			case 'bckgl':
			{
				cod = go2prevglav(glavs,currglav,currpage,current_level);
				return cod;
			}
			case 'bckpg':
			{
				cod = go2prevpage(glavs,currglav,currpage,current_level);
				return cod;
			}
			case 'fwdpg':
			{
				cod = go2nextpage(glavs,currglav,currpage,current_level);
				return cod;
			}
			case 'fwdgl':
			{
				cod = go2nextglav(glavs,currglav,currpage,current_level);
				return cod;
			}
		}
}
function go2nextglav(glavs,currglav,currpage,current_level)
{
	currglav++;
	if(currglav == glavs[current_level].length)
	{
		currglav--;
	}
	currpage=0;
	path = basefolder + glavs[current_level][currglav][currpage];
	document.location.href = path;
	cod = new String (currglav);
	cod+='_';
	cod+=currpage;
	return cod;
}
function go2nextpage(glavs,currglav,currpage,current_level)
{
	currpage++;
	if (glavs[current_level][currglav][currpage]==null)
	{
		currpage=0;
		if(currglav == glavs[current_level].length-1)
		{
			currpage=glavs[current_level][currglav].length-1;
			path = basefolder + glavs[current_level][currglav][currpage];
			document.location.href = path;
			cod = new String (currglav);
			cod+='_';
			cod+=currpage;
			return cod;
		}
	cod = go2nextglav(glavs,currglav,currpage,current_level);
	return cod;
	}
	else
	{
		path = basefolder + glavs[current_level][currglav][currpage];
		document.location.href = path;
		cod = new String (currglav);
		cod+='_';
		cod+=currpage;
		return cod;
	}
}
function go2prevglav(glavs,currglav,currpage,current_level)
{
	currglav--;
	if(currglav==-1)
	{
		currglav++;
	}
	currpage=0;
	path = basefolder + glavs[current_level][currglav][currpage];
	document.location.href = path;
	cod = new String (currglav);
	cod+='_';
	cod+=currpage;
	return cod;
}
function go2prevpage(glavs,currglav,currpage,current_level)
{
	currpage--;
	if (currpage==-1)
	{
		currglav--;
		if(currglav==-1)
		{
			currglav++;
			currpage++;
			path = basefolder + glavs[current_level][currglav][currpage];
			document.location.href = path;
			cod = new String (currglav);
			cod+='_';
			cod+=currpage;
			return cod;
		}
		else
		{
		currpage=glavs[current_level][currglav].length-1;
		path = basefolder + glavs[current_level][currglav][currpage];
		document.location.href = path;
		cod = new String (currglav);
		cod+='_';
		cod+=currpage;
		return cod;
		}
	}
	path = basefolder + glavs[current_level][currglav][currpage];
	document.location.href = path;
	cod = new String (currglav);
	cod+='_';
	cod+=currpage;
	return cod;
}
//-------8<-----------------8<---------------8<-------------8<--------------end script code
