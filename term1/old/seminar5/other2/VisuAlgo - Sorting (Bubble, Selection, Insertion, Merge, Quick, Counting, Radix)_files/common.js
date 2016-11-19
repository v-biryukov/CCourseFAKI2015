var PHP_DOMAIN = ""; // transition... "http://algorithmics.comp.nus.edu.sg/~onlinequiz";

/*
var fbAccessToken = "";

// check status of facebook login
function fbStatusChangeCallback(response) {
  // The response object is returned with a status field that lets the
  // app know the current login status of the person.
  // Full docs on the response object can be found in the documentation
  // for FB.getLoginStatus().
  if (response.status === 'connected') {
    // sync facebook session with server
    // Logged into your app and Facebook.
    FB.api('/me', function(response) {
      $('#login-link').html('Logout <b>' + response.name + '</b>');
    });
  } else {
    $('#login-link').text('Login');
  }
  if (response.authResponse !== undefined) {
    fbAccessToken = response.authResponse.accessToken;
  }
}

window.fbAsyncInit = function() {
  FB.init({
    appId: '512208288834370', // 519543441523397',
    cookie: true, // enable cookies to allow the server to access 
    // the session
    xfbml: true, // parse social plugins on this page
    version: 'v2.1' // use version 2.1
  });

  // This function gets the state of the person visiting this page and can return one of three states to the callback you provide.  They can be:
  // 1. Logged into your app ('connected')
  // 2. Logged into Facebook, but not your app ('not_authorized')
  // 3. Not logged into Facebook and can't tell if they are logged into your app or not.
  FB.getLoginStatus(function(response) {
    fbStatusChangeCallback(response);
  });
};

// Load the SDK asynchronously
(function(d, s, id) {
  var js, fjs = d.getElementsByTagName(s)[0];
  if (d.getElementById(id))
      return;
  js = d.createElement(s);
  js.id = id;
  js.src = "//connect.facebook.net/en_US/sdk.js";
  fjs.parentNode.insertBefore(js, fjs);
}(document, 'script', 'facebook-jssdk'));
*/

// surprise colour!
// Referenced to in  home.js and viz.js also
var colourArray = ["#52bc69", "#d65775"/*"#ed5a7d"*/, "#2ebbd1", "#d9513c", "#fec515", "#4b65ba", "#ff8a27", "#a7d41e"]; // green, pink, blue, red, yellow, indigo, orange, lime

function disableScroll() { $('html').css('overflow', 'hidden'); }

function enableScroll() { $('html').css('overflow', 'visible'); }

function replaceAll(find, replace, str) { return str.replace(new RegExp(find, 'g'), replace); }

function getColours() {
  var generatedColours = new Array();
  while (generatedColours.length < 4) {
    var n = (Math.floor(Math.random() * colourArray.length));
    if ($.inArray(n, generatedColours) == -1)
      generatedColours.push(n);
  }
  return generatedColours;
}

function customAlert(msg) {
  $('#custom-alert p').html(msg);
  var m = -1 * ($('#custom-alert').outerHeight() / 2);
  $('#custom-alert').css('margin-top', m + 'px');
  $('#dark-overlay').fadeIn(function() {
    $('#custom-alert').fadeIn(function() {
      setTimeout(function() {
        $('#custom-alert').fadeOut(function() {
          $('#dark-overlay').fadeOut();
        });
      }, 1000);
    });
  });
}

function showLoadingScreen() {
  $('#loading-overlay').show();
  $('#loading-message').show();
}

function hideLoadingScreen() {
  $('#loading-overlay').hide();
}

function getQueryVariable(variable) {
  var query = window.location.search.substring(1);
  var vars = query.split('&');
  for (var i = 0; i < vars.length; i++) {
    var pair = vars[i].split('=');
    if (decodeURIComponent(pair[0]) == variable)
      return decodeURIComponent(pair[1]);
  }
  return "";
}

var generatedColours = getColours();
var surpriseColour = colourArray[generatedColours[0]];
var colourTheSecond = colourArray[generatedColours[1]];
var colourTheThird = colourArray[generatedColours[2]];
var colourTheFourth = colourArray[generatedColours[3]];

$(function() {
  // $('#login-link').click(function() {
  //       if ($('#login-link').text() == 'Login') {
  //           $('#login-overlay').fadeIn('fast');
  //           $('#login-overlay-content').show();
  //           disableScroll();
  //       } else {
  //           FB.logout(function(response) {
  //               fbStatusChangeCallback(response);
  //           });
  //       }
  //   });
  //   /*-------LOG IN AUTHENTICATION-------*/
  //   $('#login-overlay-content #login-go').click(function() {
  //       FB.login(function(response) {
  //           fbStatusChangeCallback(response);
  //           $('#login-overlay').fadeOut('fast');
  //           $('#login-overlay-content').hide();
  //       });
  //   });
  //   /*-------LOG IN CSS-------*/
  //   $('#login-id').focusin(function() {
  //       $(this).css('box-shadow', '0px 0px 3px ' + surpriseColour + ' inset');
  //       if ($(this).val() == "user id") {
  //           $(this).css('color', 'black');
  //           $(this).val("");
  //       }
  //   }).focusout(function() {
  //       $(this).css('box-shadow', '0px 0px 3px #929292 inset');
  //       if ($(this).val() == "") {
  //           $(this).css('color', '#aaa');
  //           $(this).val("user id");
  //       }
  //   });
  //   $('#login-pw').focusin(function() {
  //       $(this).css('box-shadow', '0px 0px 3px ' + surpriseColour + ' inset');
  //       if ($(this).val() == "password") {
  //           $(this).attr('type', 'password');
  //           $(this).css('color', 'black');
  //           $(this).val("");
  //       }
  //   }).focusout(function() {
  //       $(this).css('box-shadow', '0px 0px 3px #929292 inset');
  //       if ($(this).val() == "") {
  //           $(this).css('color', '#aaa');
  //           $(this).attr('type', 'text');
  //           $(this).val("password");
  //       }
  //   });
  // $('#login-overlay').click(function() {
  //   $('#login-overlay').fadeOut('fast');
  //   enableScroll();
  // });

  // $('#login-overlay-content').click(function(event) {
  //   event.stopPropagation();
  // });

  $('.links').css('background', surpriseColour);
  $('.right-links').css('background', surpriseColour);
  $('#login-go').css('background', surpriseColour);

  $('#about').html(
"<h4>About VisuAlgo</h4><img class='close-overlay' src='img/cross_white.png'>" +
"<div class='content'>" +
"<p>VisuAlgo was conceptualised in 2011 by Dr Steven Halim as a tool to help his students better understand data structures and algorithms, by allowing them to learn the basics on their own and at their own pace.</p>" + //  VisuAlgo is like a 24/7 copy of himself. Together with some of his students from the National University of Singapore (see the 'Team'), a series of visualisations were developed and consolidated, from simple sorting algorithms to complex graph data structures and algorithms, and also string+geometry algorithms.</p>" +
"<p>VisuAlgo contains <b>many advanced algorithms</b> that are discussed in Dr Steven Halim's book (<a href='http://cpbook.net' target='_blank'>'Competitive Programming'</a>, co-authored with his brother Dr Felix Halim) and beyond. Today, some of these advanced algorithms visualization/animation can <b>only</b> be found in VisuAlgo.</p>" +  // For example, in <a href='dfsbfs.html' target='_top'>Graph Traversal visualization</a>, we do not just discuss the standard Depth-First Search (DFS) and Breadth-First Search (BFS) algorithms, but also their variants, e.g. the modifications of DFS for finding Articulation Points (Cut Vertex) and Bridges, Tarjan's and Kosaraju's DFS-like algorithms for finding Strongly Connected Components (SCCs) of a directed graph, and we also have feature to visualize the implication graph of a small 2-SAT(isfiablity) instance and check if the instance is satisfiable.</p>" +
"<p>Though specifically designed for <a href='http://www.nus.edu.sg' target='_blank'>NUS</a> students taking various data structure and algorithm classes (e.g. <a href='http://nusmods.com/modules/CS1010' target='_blank'>CS1010</a>, <a href='http://nusmods.com/modules/CS1020' target='_blank'>CS1020</a>, <a href='http://nusmods.com/modules/CS2010' target='_blank'>CS2010</a>, <a href='http://nusmods.com/modules/CS2020' target='_blank'>CS2020</a>, <a href='http://nusmods.com/modules/CS3230' target='_blank'>CS3230</a>, and <a href='http://nusmods.com/modules/CS3233' target='_blank'>CS3233</a>), as advocators of online learning, we hope that curious minds around the world will find these visualisations useful too.</p>" +
"<p>VisuAlgo is not designed to work well on small touch screens (e.g. smartphones) from the outset due to the need to cater for many complex algorithm visualizations that require lots of pixels and click-and-drag gestures for interaction. The minimum screen resolution for a respectable user experience is 1024x768 and only the landing page is relatively mobile-friendly.</p>" +
// "<p><strong><span style='line-height: 200%;'>Ongoing developments</span></strong></p>" +
"<p>VisuAlgo is an ongoing project and more complex visualisations are still being developed. The following visualization is next in line to be developed by our team: Tortoise and Hare (Floyd's) Cycle-Finding algorithm</p>" + // Shortest Paths Faster Algorithm (SPFA), etc.</p>" +
"<p>However, the most exciting development is an automated question generator and verifier (the online quiz system) that allows student to test their knowledge of basic data structures and algorithms. The questions are <b>randomly generated</b> via some rules and students' answers are <b>instantly and automatically graded</b> upon submission to our grading server. This online quiz system, when it is adopted by more CS instructors worldwide, should technically eliminate <b>manual</b> basic data structure and algorithm questions from typical Computer Science examinations in many Universities. By setting a small (but non-zero) weightage on passing the online quiz, a CS instructor can (significantly) increase his/her students mastery on these basic questions as the students have virtually infinite number of training questions that can be verified instantly before they take the online quiz. To try this exciting online quiz feature, start <a href='training.html'>'training'</a>.</p>" +
"<p>The training mode currently contains questions for 12 visualization modules. We will soon add the remaining 7 visualization modules: Segment Tree, BIT, Network Flow, Matching, Suffix Tree, Suffix Array, and Geometry to cater for future NUS CS3233 module.</p>" +
"<p>Another active branch of development is the internationalization sub-project of VisuAlgo. We want to prepare a database of CS terminologies for all English text that ever appear in VisuAlgo system. This is a big task and requires crowdsourcing. Once the system is ready, we will invite VisuAlgo visitors to contribute, especially if you are not a native English speaker. Currently, we have also written public notes about VisuAlgo in various languages: <a href='http://www.weibo.com/p/230418436e9ee80102v4rk' target='_blank'><u>Chinese</u></a>, <a href='https://www.facebook.com/notes/steven-halim/httpidvisualgonet-visualisasi-struktur-data-dan-algoritma-dengan-animasi/10153236934439689' target='_blank'><u>Indonesian</u></a>, <a href='http://blog.naver.com/visualgo_nus' target='_blank'><u>Korean</u></a>, <a href='https://www.facebook.com/groups/163215593699283/permalink/824003417620494/' target='_blank'><u>Vietnamese</u></a>, <a href='http://pantip.com/topic/32736343' target='_blank'><u>Thai (first link)</u></a>, and <a href='https://www.blognone.com/node/61764' target='_blank'><u>Thai (second link)</u></a>.</p>" +
"</div>"
  );

  $('#team').html(
"<h4>The team</h4><img class='close-overlay' src='img/cross_white.png'>" +
"<div class='content'>" +
"<p><strong><span style='line-height: 200%;'>Project leader (Jul 2011-present)</span></strong><br><a href='http://www.comp.nus.edu.sg/~stevenha/' target='_blank'>Dr Steven Halim</a>, Lecturer, SoC, NUS</p>" +
"<p><strong><span style='line-height: 200%;'>Advisor (Jul 2011-present)</span></strong><br><a href='http://felix-halim.net/' target='_blank'>Felix Halim</a></p>" +
"<p><strong><span style='line-height: 200%;'>Initial Programmers, Undergraduate Student Researchers 1 (Jul 2011-Apr 2012)</span></strong><br>Koh Zi Chun, <a href='http://roticv.rantx.com/' target='_blank'>Victor Loh Bo Huai</a></p>" +
"<p><strong><span style='line-height: 200%;'>Round 1: Final Year Project students (Jul 2012-Dec 2013)</span></strong><br>Phan Thi Quynh Trang, Peter Phandi, Albert Millardo Tjindradinata, Nguyen Hoang Duy</p>" +
"<p><strong><span style='line-height: 200%;'>Round 2: Final Year Project students (Jun 2013-Apr 2014)</span></strong><br><a href='http://www.rosemarietan.com/' target='_blank'>Rose Marie Tan Zhao Yun</a>, Ivan Reinaldo</p>" +
"<p><strong><span style='line-height: 200%;'>Undergraduate Student Researchers 2 (May 2014-Jul 2014)</span></strong><br>Jonathan Irvin Gunawan, Nathan Azaria, Ian Leow Tze Wei, Nguyen Viet Dung, Nguyen Khac Tung, Steven Kester Yuwono, Cao Shengze, Mohan Jishnu</p>" +
"<p><strong><span style='line-height: 200%;'>Round 3: Final Year Project and UROP students (Jun 2014-Apr 2015)</span></strong><br>Erin Teo Yi Ling, Wang Zi</p>" +
"<p><strong><span style='line-height: 200%;'>Acknowledgements</span></strong><br>This project is made possible by the generous <a href='http://www.cdtl.nus.edu.sg/teg/' target='_blank'>Teaching Enhancement Grant</a> from NUS Centre for Development of Teaching and Learning.</p>" +
"</div>"
  );

  $('#termsofuse').html(
"<h4>Terms of use</h4><img class='close-overlay' src='img/cross_white.png'>" +
"<div class='content'>" +
"<p>VisuAlgo is created free of charge for Computer Science community on earth. If you like VisuAlgo, the only payment that we ask of you is for you to <b>tell the existence of VisuAlgo to other Computer Science students/instructors</b> that you know =) via Facebook, Twitter, blog review, email, etc.</p>" +
"<p>If you are a data structure and algorithm <b>student/instructor</b>, you are allowed to use this website for your classes. You can take screen shots from this website and use the screen shots elsewhere as long as you cite this website and/or list of publications below as reference. However, you are <b>NOT</b> allowed to download VisuAlgo files and <b>host it locally</b> on your own website as it is <b>plagiarism</b>. Using the offline copy of VisuAlgo for your personal usage is fine.</p>" +
"<p>Note that VisuAlgo's online quiz component is by nature server-side only and there is no easy way to save the server-side scripts and databases locally. The general public can only use the 'training mode' to access these online quiz system. Currently the 'test' and 'answer' mode is a more controlled environment for using these randomly generated questions and automatic verification for a <b>real</b> examination in NUS. Other interested CS instructor should contact Steven if you want to try.</p>" +
"<p><strong><span style='line-height: 200%;'>List of Publications</span></strong></p>" +
"<p>This work has been presented briefly at the CLI Workshop at the ACM ICPC World Finals 2012 (Poland, Warsaw) and at the IOI Conference at IOI 2012 (Sirmione-Montichiari, Italy). You can click <a href='http://www.ioinformatics.org/oi/shtm/INFOL099.shtml' target='_blank'>this link</a> to read our 2012 paper about this system (it was not yet called VisuAlgo back in 2012).</p>" +
"<p>This work is done mostly by my past students. The most recent final reports and/or presentations are here: <a href='fyp/erin-report.pdf' target='_blank'>Erin (report)</a>, <a href='fyp/erin-presentation.pdf' target='_blank'>Erin (presentation)</a>, <a href='fyp/wangzi-report.pdf' target='_blank'>Wang Zi (report)</a>, <!--<a href='http://prezi.com/dp0js7cbk_6o/present/?auth_key=3mtte30&follow=t5stkpdnjdz5&kw=present-dp0js7cbk_6o&rc=ref-134763646' target='_blank'>Wang Zi (presentation)</a>, --><a href='fyp/rose-report.pdf' target='_blank'>Rose (report)</a>, <a href='fyp/ivan-report.pdf' target='_blank'>Ivan (report)</a>.</p>" +
"<p><strong><span style='line-height: 200%;'>Bug Reports or Request for New Features</span></strong></p>" +
"<p>VisuAlgo is not a finished project. Dr Steven Halim is still actively improving VisuAlgo. If you are using VisuAlgo and spot a bug in any of our visualization page/online quiz tool or if you want to request for new features, please contact Dr 'Steven Halim'. His contact is the concatenation of his name and add gmail dot com.</p>" +
"</div>"
  );

  $('.colour').css("color", surpriseColour); // name
  $('h4').css("background-color", surpriseColour); // about, contact us etc. button background

  // title
  $('#title a').click(function() {
    $('#title a').removeClass('selected-viz');
    $(this).addClass('selected-viz');
  });

  // overlays stuffs
  $('#trigger-about').click(function() {
    if ($(window).width() > 600) {
      $('#dark-overlay').fadeIn(function() {
        $('#about').fadeIn();
      });
    }
    else
      alert('Sorry, this dialog is too big. Please load it on bigger screen');
  });

  $('#trigger-team').click(function() {
    if ($(window).width() > 600) {
      $('#dark-overlay').fadeIn(function() {
        $('#team').fadeIn();
      });
    }
    else
      alert('Sorry, this dialog is too big. Please load it on bigger screen');
  });

  $('#trigger-terms').click(function() {
    if ($(window).width() > 600) {
      $('#dark-overlay').fadeIn(function() {
        $('#termsofuse').fadeIn();
      });
    }
    else
      alert('Sorry, this dialog is too big. Please load it on bigger screen');
  });

  $('.close-overlay').click(function() {
    $('.overlays').fadeOut(function() {
      $('#dark-overlay').fadeOut();
    });
  });

  $('#dark-overlay').click(function() {
    $('.overlays').fadeOut();
    $('#dark-overlay').fadeOut();
  });
});

<!-- Q: Are you going to make VisuAlgo an open-source project so that other developers can extend it, edit certain visualizations to their liking, edit the language of the visualizations, etc?<br>  A: We are still undecided about this. -->
<!-- We also realize the importance of this component to provide holistic learning experience and we will support the internationalization feature for this part too. -->

<!-- <li>Q: The <a href="test.html">test</a> and the <a href="answerkey.html">answer</a> buttons appear only occassionally. When they appear, I cannot access them as it asks for password. Is it normal?<br> -->
<!-- A: Yes, this test mode is only for Dr Steven Halim's current CS2010 students (the next iteration will be Aug-Nov 2015). The other CS students can access the <a href="training.html">training mode</a> to see similar set of random questions.<br> Soon, we will open a 'lecturer mode' so that other CS lecturers worldwide can use this tool to administer online test for their students.<br> -->
