// $Id: betterselect.js,v 1.2.2.1 2009/02/27 11:22:00 marktheunissen Exp $

Drupal.behaviors.initBetterSelect = function(context) {
  $('.better-select .form-checkboxes input[type="checkbox"]').click(function(){
    this.checked ? $(this).parent().parent().addClass('hilight') : $(this).parent().parent().removeClass('hilight');
  }).filter(":checked").parent().parent().addClass('hilight');
}

