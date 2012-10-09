var newPlay = newPlay || {};

/*
 * Contact user invite system
 */
newPlay.validateContact = function(name, email, submit) {
  newPlay.validateContact.data = {};
  var name = name || 'undefined';
  var email = email || 'undefined';
  var submit = submit || false;

  $.ajax({
    url: Drupal.settings.basePath + 'newplay_reference/user/' + name + '/' + email + '/' + submit,
    dataType: 'json',
    async: false,
    success: function(data) {
      // do stuff with the data
      newPlay.validateContact.data = data;
      // console.log(newPlay.validateContact.data);
      
      // Most of the scenarios should not have an error so lets remove it 
      // first then add it in when necessary
      $('#edit-contact-email-wrapper').children('input').removeClass('error');
      
      if (newPlay.validateContact.data.status == 'failed') {
        $('#edit-contact-email-wrapper').insertAfter('#edit-field-user-contact-0-uid-uid-wrapper').slideDown().find('#edit-contact-email').addClass('error');
        newPlay.errorScroll();
      } else if (newPlay.validateContact.data.status == 'found email') {
        // If a user was found using the email, set the name on the form
        $('#edit-field-user-contact-0-uid-uid').val(newPlay.validateContact.data.name);
      } else if (newPlay.validateContact.data.status == 'found name') {
        // Do stuff to the email field if the name is found
      } else if (newPlay.validateContact.data.status == 'user created') {
        $('#edit-field-user-contact-0-uid-uid').val(newPlay.validateContact.data.name);
      }
      
      // If we're validating on submit, and everything goes ok, then submit
      if (submit == true && newPlay.validateContact.data.name != 'failed') {
        // $('#node-form').submit();
      }
    }
  });
}

// @TODO: merge with newPlay.validateContact function above
newPlay.validateContactCustomFields = function(element, name, email, submit) {
  newPlay.validateContact.data = {};
  
  var name = name || 'undefined';
  var email = email || 'undefined';
  var submit = submit || false;
  
  // never create anything
  var submit = false;

  $.ajax({
    url: Drupal.settings.basePath + 'newplay_reference/user/' + name + '/' + email + '/' + submit,
    dataType: 'json',
    async: false,
    success: function(data) {
      // do stuff with the data
      newPlay.validateContact.data = data;
      // console.log(newPlay.validateContact.data);
      
      // Most of the scenarios should not have an error so lets remove it 
      // first then add it in when necessary
      $(element).find('input').removeClass('error');
      
      if (newPlay.validateContact.data.status == 'failed') {
        $(element)
          .find('.contact-email-wrapper')
          .slideDown()
          .find('.contact-email-field')
          .addClass('error');
        newPlay.errorScroll();
      } else if (newPlay.validateContact.data.status == 'found email') {
        // If a user was found using the email, set the name on the form
        $(element)
          .find('.contact-name-field')
          .val(newPlay.validateContact.data.name);
      } else if (newPlay.validateContact.data.status == 'found name') {
        // Do stuff to the email field if the name is found
        
      } else if (newPlay.validateContact.data.status == 'user created') {
        $(element)
          .find('.contact-name-field')
          .val(newPlay.validateContact.data.name);
      } 
      
      // If we're validating on submit, and everything goes ok, then submit
      if (submit == true && newPlay.validateContact.data.name != 'failed') {
        // $('#node-form').submit();
      }
    }
  });
}


// I think this could be used for any node reference field 
newPlay.validateContactPlay = function(type, element, name, email, nodeRef, submit) {
  var nodeId = nodeRef.replace(/.*:/, '').replace(']', '');
  
  var name = name || 'undefined';
  var email = email || 'undefined';
  var submit = submit || false;
  
  $.ajax({
    // url: Drupal.settings.basePath + 'newplay_reference/artist/' + name + '/' + email + '/' + nodeId + '/' + submit,
    url: Drupal.settings.basePath + 'newplay_reference/node/' + type + '/' + name + '/' + email + '/' + nodeId + '/' + submit,
    dataType: 'json',
    async: false,
    success: function(data) {
      // do stuff with the data
      newPlay.validateContact.data = data;
      // console.log(newPlay.validateContact.data);
      
      if (newPlay.validateContact.data.status == 'contact needed') {        
        
        if ($(element).hasClass('contact-info-processed')) {
          // The form is there but there is no info
          // Set error message
          // console.log($(element).find('.contact-artist-wrapper .contact-artist-field'));
          $(element)
            .find('.contact-artist-wrapper .contact-artist-field')
            .removeClass('error')
            .end()
						.find('.contact-name-wrapper')
						.slideDown()
						.find('.contact-name-field')
						.addClass('error');
						
					newPlay.errorScroll();
					
        } else {
          $(element).addClass('contact-info-processed');
          // newPlay.insertContactFields(element);
          newPlay.insertContactFields($(element).children('#edit-field-artist-nid-nid'), 'organization');
        }        
      } else {
        // console.log($(element));
        $(element).find('.contact-name-field').removeClass('error');
        $(element).find('.contact-artist-field').removeClass('error');
      }
    }
  });
}


/**
 * Function to validate and submit Org field on the event form
 * 
 * @TODO: Merge with newPlay.validateContactPlay()
 */
newPlay.validateContactOrg = function(element, name, email, nodeRef, submit) {
  var nodeId = nodeRef.replace(/.*:/, '').replace(']', '');
  
  var name = name || 'undefined';
  var email = email || 'undefined';
  var submit = submit || false;
  
  $.ajax({
    url: Drupal.settings.basePath + 'newplay_reference/node/' + 'organization' + '/' + name + '/' + email + '/' + nodeId + '/' + submit,
    dataType: 'json',
    async: false,
    success: function(data) {
      // do stuff with the data
      newPlay.validateContact.data = data;
      // console.log(newPlay.validateContact.data);
      
      if (newPlay.validateContact.data.status == 'contact needed') {        
        
        if ($(element).hasClass('contact-info-processed')) {
          // Set error somewhere? I think this should happen
          // The form is there but there is no info
        } else {
          $(element).addClass('contact-info-processed');
          newPlay.test = element;
          // @TODO: test code
          newPlay.insertContactFields($(element).children('#edit-field-related-theater-nid-nid'), 'organization');
        }        
      }
    }
  });
}


/**
 * Function to validate Play field on the event form
 * 
 * Copy of newPlay.validateContactOrg()
 * @TODO: Merge with newPlay.validateContactPlay()
 */
newPlay.validateContactPlayEvent = function(element, name, email, nodeRef, submit) {
  var nodeId = nodeRef.replace(/.*:/, '').replace(']', '') || 'undefined';
  
  
  var name = name || 'undefined';
  var email = email || 'undefined';
  var submit = submit || false;
  var artist = artist || 'undefined';
  
  $.ajax({
    url: Drupal.settings.basePath + 'newplay_reference/play/' + 'play' + '/' + name + '/' + email + '/' + nodeId + '/' + artist + '/' + submit,
    dataType: 'json',
    async: false,
    success: function(data) {
      // do stuff with the data
      newPlay.validateContact.data = data;
      // console.log(newPlay.validateContact.data);
      
      if (newPlay.validateContact.data.status == 'contact needed') {        
        
        if ($(element).hasClass('contact-info-processed')) {
          // Set error somewhere? I think this should happen
          // The form is there but there is no info
          $(element).find('.contact-name-wrapper').slideDown();
          newPlay.errorScroll();
        } else {
          $(element).addClass('contact-info-processed');
          newPlay.test = element;
          // @TODO: Replace with something that adds a Geneartive artist field, which then add teh Contact fields stuff to that
          newPlay.insertContactFields($(element).children('#edit-field-related-play-nid-nid'), 'artist');
        }        
      }
    }
  });
}



/*
 * Function to add name and email fields to a node reference
 * @TODO: There is an issue with 'element' sometimes being the wrapper and sometimes being the field. Standardize on wrapper
 */
newPlay.insertContactFields = function(element, type, existingNameField) {  
  // Parent element for all contact fields
  $('<div></div>').addClass('contact-wrapper').appendTo($(element).parent());
  
  /* Name */
  // Get ready to be able to pass it an existing field instead of creating new ones
  var contactNameWrapper = '';
  var contactNameField = '';
  
  // Values for different fields depending on whether it's an org or an artist
  var fieldText = {
    organization: {
      nameLabel: "Organization's Content Administrator Name",
      nameHelp: "Please provide the name of the lead organization's content administrator who is most likely to take the lead in updating and contributing information.",
      emailHelp: "Please provide the email for the lead organization's contact person."
    },
    artist: {
      nameLabel: "Artist's Content Administrator",
      nameHelp: "Please provide the name of the artist's content administrator (this could be the same as the artist) who is most likely to take the lead in updating and contributing information about this artist.",
      emailHelp: "Please provide the email for the above contact person."
    }
  };
  
  if (existingNameField) {
    contactNameWrapper = $(existingNameField).parent();
    contactNameField = existingNameField;
  } else {
    contactNameWrapper = $('<div></div>')
      .addClass('contact-name-wrapper')
      .hide()
      .appendTo(element.siblings('.contact-wrapper'));
    $('<label></label>').attr('for', 'contact-name-field').html(fieldText[type]['nameLabel']).appendTo(contactNameWrapper);
    contactNameField = $('<input type="text"></input>').attr({
      'name': 'contact-name-field',
      'class': 'form-text text contact-name-field'
    });
  }
    
  contactNameField.blur(function() {
    if (contactNameField.val().length > 0) {
      newPlay.validateContactCustomFields(element.parent(), $(element).siblings('.contact-wrapper').find('.contact-name-field').val(), $(element).siblings('.contact-wrapper').find('.contact-email-field').val(), false);
    }
  })
  .appendTo(contactNameWrapper);
  
  var contactNameDescription = $('<div></div>')
    .addClass('description')
    .html(fieldText[type]['nameHelp'])
    .appendTo(contactNameWrapper);
  
  
  /* Generative artist field for plays */
  if (type == 'artist') {
    contactArtistWrapper = $('#edit-value-wrapper')
      .hide()
      .addClass('contact-artist-wrapper')
      .prependTo(element.siblings('.contact-wrapper'));

    $('#edit-value')
    .addClass('contact-artist-field')
    .blur(function() {
      if ($(this).val().length > 0) {
        newPlay.validateContactPlay('artist', element.parent(), $('.contact-name-field').val(), $('.contact-email-field').val(), $(this).val(), false);
      }
    });
  }  
  
  /* Email */
  var contactEmailWrapper = $('<div></div>')
    .addClass('contact-email-wrapper')
    .hide()
    .appendTo(element.siblings('.contact-wrapper'));

  $('<label></label>').attr('for', 'contact-email-field').html('Content Administrator Email').appendTo(contactEmailWrapper);
  
  
  $('<input type="text"></input>').attr({
    'name': 'contact-email-field',
    'class': 'form-text text contact-email-field'
  })
  .blur(function() {
    newPlay.validateContactCustomFields(element.parent(), $('.contact-name-field').val(), $('.contact-email-field').val(), false);
  })
  .appendTo(contactEmailWrapper);
  
  var contactEmailDescription = $('<div></div>')
    .addClass('description')
    .html(fieldText[type]['emailHelp'])
    .appendTo(contactEmailWrapper);
  
  if (type == 'artist') {
    $(contactArtistWrapper).children('.contact-artist-field').addClass('error');
    $(contactArtistWrapper).slideDown();
    newPlay.errorScroll();
  } else {
    $(contactNameWrapper).children('.contact-name-field').addClass('error');
    $(contactNameWrapper).slideDown();  
    newPlay.errorScroll();
  }
  
    // The email return handling could be taken care of by returnSubmit()
    // by commenting the next line out
    newPlay.enableReturnKey($(contactEmailWrapper).children('.contact-email-field'));
    newPlay.enableReturnKey($(contactNameWrapper).children('.contact-name-field'));
}


/*
 * "Other" field show/hide toggle
 */
newPlay.initOtherField = function(checkboxWrapper, otherField) {
  var checkbox = checkboxWrapper.find('input[type=checkbox]');
  otherField = otherField.remove().insertAfter(checkboxWrapper.parent().parent().parent().find('.form-checkboxes'));

  otherField
    .addClass('hilight') // from betterselect
    .css('margin-top', 0);

  checkboxWrapper.parent()
    .parent()
    .css('margin-bottom', 0)
    .parent()
    .css('margin-bottom', 0); 

  // If it's already checked on load show it
  var visibility = function() {
    if (checkbox.attr('checked') == true) {
      otherField.show();
    } else {
      otherField.hide();
    }
  }

  visibility();

  // If you check it show
  checkbox.change(function() {
    visibility(); 
  });
}

/*
 * Helper functions for overriding autocomplete
 */
// Set up general bucket for autocomplete functions and variables
newPlay.autocomplete = {};

/*
 * Autocomplete function for orgs
 */
newPlay.autocomplete.org = function (node) {
  var fieldCheck = $('#edit-field-location-0-street').val().length + $('#edit-field-location-0-city').val().length + $('#edit-field-location-0-province').val().length + $('#edit-field-location-0-postal-code').val().length;
  
  if (fieldCheck < 1) {
    newPlay.autocompleteNode = node;
    newPlay.autocomplete.org.nodeId = node.autocompleteValue.replace(/.*:/, '').replace(']', '');

    $.ajax({
      url: Drupal.settings.basePath + 'node/' + newPlay.autocomplete.org.nodeId + '/location',
      dataType: 'json',
      beforeSend: function() {
        $('#edit-field-location-0-street').addClass('form-autocomplete throbbing');
        $('#edit-field-location-0-city').addClass('form-autocomplete throbbing');
        $('#edit-field-location-0-province').addClass('throbbing');
        $('#edit-field-location-0-postal-code').addClass('form-autocomplete throbbing');
      },
      success: function(data) {
        // do stuff with the data
        if (data.items.length > 0) {
          $('#edit-field-location-0-street').val(data.items[0].item.Street);
          $('#edit-field-location-0-city').val(data.items[0].item.City);
          $('#edit-field-location-0-province').val(data.items[0].item.Province);
          $('#edit-field-location-0-postal-code').val(data.items[0].item['Postal Code']);
        }
      },
      complete: function() {
        $('#edit-field-location-0-street').removeClass('form-autocomplete throbbing error');
        $('#edit-field-location-0-city').removeClass('form-autocomplete throbbing error');
        $('#edit-field-location-0-province').removeClass('throbbing error');
        $('#edit-field-location-0-postal-code').removeClass('form-autocomplete throbbing error');
      }
    });
    
  }
}

// Autocomplete function for artists
newPlay.autocomplete.artist = function (node) {
  newPlay.autocompleteNode = node;
  newPlay.autocomplete.artist.nodeId = node.autocompleteValue.replace(/.*:/, '').replace(']', '');
  // console.log(newPlay.autocomplete.artist.nodeId);
}


/**
 * Function to format qtip links
 * 
 * element is a jquery object
 */
newPlay.formatLinksBubble = function(element, newId, width) {
  if (element.hasClass('links-processed')) {
    // return;
  } else {
    // Figure out title
    var linkText = 'Link';
    if (element.children('h2').length > 0) {
      linkText = element.children('h2').remove().html();
    } else if (element.find('h3').length > 0) {
      linkText = element.find('h3').remove().html();
    }
    // Use width if it's there
    var width = width || 215;
    // Build button
    $('<a></a>')
      .attr({
        'id': newId
      })
      .css('cursor', 'pointer')
      .html(linkText)
      .insertBefore(element);

    // Add links as tool tip
    $('#' + newId).qtip({
      content: element.find('.content'),
      // content: element.find('.item-list ul'),
      position: {
        adjust: {
          screen: true
      },
      corner: {
       target: 'bottomMiddle',
       tooltip: 'topMiddle'
      }
      },
      show: 'click',
      hide: { 
       when: 'unfocus',
       fixed: false 
      },

      style: {
       width: width,
       'color': '#000000',
       'padding': '0',
       background: '#FFFFFF',
       border: {
         width: 7,
         color: '#666666'
       },
       tip: {
         corner: 'topMiddle',
         size: {
           x: 40,
           y: 15
         }
       }
      }

    });
    
    element.addClass('links-processed');
    element.hide();
    
  }
}


/**
 * Apply accordion to additional info region.
 */
newPlay.overlayContentStyle  = function(context) {
  // Using jQuery UI accordion styling for now
  // active: 'FALSE' means nothing is open when the page loads
  $('div.panel-overlay div.additional-info').show().accordion({
    active: 'FALSE',
    collapsible: true
  });
}


/*
 * Embedable Badge Block
 * Direct link URL
 */
// Function for showing form to include selecting text etc
newPlay.embedToggle = function() {
  $('#embed-badge-block form').slideToggle('fast', function() {
    $('#embed-badge-block form input').select();
  });
}

newPlay.shareLinkToggle = function() {
  $('#share-link-block form').slideToggle('fast', function() {
    $('#share-link-block form input').select();
  });
}

// Build link
newPlay.embedInteraction = function() {
  if ($('#embed-badge-show').length > 0) {
    // return;
  } else {
    $('<a></a>')
      .attr({
        'id': 'embed-badge-show',
        'href': '#'
      })
      .html($('#embed-badge-link label').remove().html())
      .prependTo('#embed-badge-link')
      .click(function(event) {
        event.preventDefault();
        newPlay.embedToggle();
      });

      $('#embed-badge-image img').click(function() {
        newPlay.embedToggle();
      }).css('cursor', 'pointer');

      $('#embed-badge-block form input').hover(function() {
        $('#embed-badge-block form input').select();
      });
  } 
}

newPlay.shareLinkInteraction = function() {
  if ($('#share-link-show').length > 0) {
    // return;
  } else {
    $('<a></a>')
      .attr({
        'id': 'share-link-show',
        'href': '#'
      })
      .html($('#share-link-link label').remove().html())
      .prependTo('#share-link-link')
      .click(function(event) {
        event.preventDefault();
        newPlay.shareLinkToggle();
      });

      $('#share-link-image img').click(function() {
        newPlay.shareLinkToggle();
      }).css('cursor', 'pointer');

      $('#share-link-block form input').hover(function() {
        $('#share-link-block form input').select();
      });
  }
}


/**
 * Function to scroll to the first error on the page
 */
newPlay.errorScroll = function() {
  if ($('.error').length > 0) {
    $('body').scrollTo($('.error:visible:first').parent(), 500);
    $('.error:visible:first').focus();
  }
}


/**
 * Function to pull the form id out of the form action
 */
newPlay.findFormId = function(string, basePath, bodyClasses) {
  var string = string;

  string = string.replace('%20', ' ').replace(basePath, '')
    .replace('node/add/', '') // Remove node/add
    .replace(/\?.*/, '') // Remove junk after edit so this works on edit forms
    .replace('edit', '') // Remove edit so this works on edit forms
    .replace('/', '').replace('/', '') // Remove slashes
    .replace(/[0-9]+/, ''); // Remove any number from the end of the path (passed arguments for example)
    
  if (string == 'node') {
    string = bodyClasses.replace(/.*node-type-/, '').replace(/\s.*/, '');
  }
  
  return string;
}


/**
 * Function to handle hitting return key in forms with crazy custom validation
 * @TODO: make this into a jquery plugin
 */
newPlay.enableReturnKey = function(element) {
  if ($(element).hasClass('return-key-enabled')) {
    
  } else {
    $(element).keypress(function(event) {
      if (event.keyCode == '13') { 
        event.preventDefault();
        $(this).trigger('blur');

        // Regardless of whether we submit the form manually, the final submission saves everything except the node we're creating. The second submit does though ??
        // $('#node-form').submit();
      }
    });
    
    $(element).addClass('return-key-enabled');
  }
}

newPlay.returnSubmit = function(form) {
  $(form).find('input').each(function() {
    if ($(this).hasClass('return-key-enabled')) {

    } else {
      $(this).keypress(function(event) {
        if (event.keyCode == '13') { 
          event.preventDefault();

          // Regardless of whether we submit the form manually, the final submission saves everything except the node we're creating. The second submit does though ??
          $('#node-form').submit();
        }
      });
      
      $(this).addClass('return-submit');
    }
    
  });
}


/** 
 * Custom form validation function (to allow us to control submit better)
 */
newPlay.formValidation = function(form) {
  $(form).find('.required').each(function() {
    if ($(this).val().length == 0) {
      $(this).addClass('error').keyup(function() {
        $(this).removeClass('error');
      });
    }
  });
  
  newPlay.errorScroll();
  
  return ($('.error').length > 0) ? false : true;
}


/**
 * Override the autocomplete found function to display edit links of matches below the field
 */
newPlay.autocompleteEditSuggestions = function() {
  /**
   * Fills the suggestion popup with any matches received
   */
  Drupal.jsAC.prototype.found = function (matches) {
    // If no value in the textfield, do not show the popup.
    if (!this.input.value.length) {
      return false;
    }

    // Prepare matches
    var ul = document.createElement('ul');
    $('#' + this.input.id + '-custom-autocomplete').remove();
    var extraHelpList = $('<div></div>').attr('id', this.input.id + '-custom-autocomplete');
    extraHelpList.html('<span class="description"><strong>It looks like we already have a record with that title. Would you like to edit that one instead?</strong></span>').append('<ul></ul>');
    var ac = this;
    
    if (this.input.id == 'edit-title') {
      for (key in matches) {

        var extraHelpItem = document.createElement('li');
        var extraHelpItemPath = Drupal.settings.basePath + 'node/' + key.replace(/.*nid:/, '').replace(']', '') + '/edit';
        $(extraHelpItem).html('<a class="edit-button" href="' + extraHelpItemPath + '">Edit</a> ' + matches[key]);
        extraHelpItem.autocompleteValue = key;
        $(extraHelpList).find('ul').append(extraHelpItem);
      }

      // Show popup with matches, if any
      if (this.popup) {
        if ($(extraHelpList).find('ul').children().length > 0) {
          var additionalMatchesContainer = $('<div></div>').insertAfter(this.input).html(extraHelpList);

        }
        else {
          $(this.popup).css({visibility: 'hidden'});
          this.hidePopup();
        }
      }
    } else {
      for (key in matches) {
        var li = document.createElement('li');
        $(li)
          .html('<div>'+ matches[key] +'</div>')
          .mousedown(function () { ac.select(this); })
          .mouseover(function () { ac.highlight(this); })
          .mouseout(function () { ac.unhighlight(this); });
        li.autocompleteValue = key;
        $(ul).append(li);
      }

      // Show popup with matches, if any
      if (this.popup) {
        if (ul.childNodes.length > 0) {
          $(this.popup).empty().append(ul).show();
        }
        else {
          $(this.popup).css({visibility: 'hidden'});
          this.hidePopup();
        }
      }
    }
    
    
    
  };
};


newPlay.addExploreFilters = function() {
  var filterExists = $('div#explore-filters');

  if(filterExists[0] === undefined) {
    var filterMarkup = '<div id="explore-filters-tab"><h3><a class="layer-show" title="Show all pins and map filters">&#0171;</a></h3></div><div id="explore-filters"><div class="hide-btn">&#0187;</div>';
    filterMarkup += '</div>';
    $('div.panel-1col-with-feeds').append(filterMarkup);

    // Grab (and adapt) markup for explore filters box.
    $('div#explore-filters').append($('form#views-exposed-form-organizations-panel-pane-1'));

    $('div#explore-filters div.hide-btn').click(function(){
      newPlay.closeExploreFilters();
    });
    
    // Put an explore button back in the header. Give it the same class as the show all button
    $('<a></a>')
      .attr('id', 'explore-filters-button')
      .html('<span>Explore</span>')
      .click(function() {
        if ($('div#explore-filters').is(':visible') === true) {
          // close filters
          newPlay.closeExploreFilters();
        } else {
          // open filters
          newPlay.openExploreFilters();
        }
      })
      // .addClass('layer-show')
      .insertBefore('div#block-views--exp-organizations-panel_pane_1');

    // Make trigger for show all button.
    $('a.layer-show').click(function(){
      newPlay.openExploreFilters();
    });
    
    $('div#explore-filters').hide();

    // Show the filters if the user previously had it open
    if ($.cookie('explore-filters') == 'true' && $('body.front').length > 0) {
      newPlay.openExploreFilters();
    }
 
  }
};


newPlay.openExploreFilters = function() {
  $('div#explore-filters').show();
  $('div#explore-filters-tab').hide();
  newPlay.layerToggle('all-events', true);
  newPlay.layerToggle('filter-results-organizations', true);
  newPlay.layerToggle('filter-results-artists', true);
  // Set cookie
  $.cookie('explore-filters', true, {expires: 7, domain: newPlay.queryString[0].replace('http://', '').replace('/', ''), path: '/'});
  return false;
};


newPlay.closeExploreFilters = function() {
  $('div#explore-filters').hide();
  $('div#explore-filters-tab').show();
  $.cookie('explore-filters', false, {expires: 7, domain: newPlay.queryString[0].replace('http://', '').replace('/', ''), path: '/'});
  return false;
};


/** 
 * Drupal Behaviors
 */
Drupal.behaviors.newPlay = function(context) {
  // Set up variables to use elsewhere
  var url = document.URL;
  newPlay.queryString = url.split('?');

   /* Bubble popup for sidebar of nodes */
   newPlay.formatLinksBubble($('#feed_links'), 'feed_button');
 
  /* Apply accordion to additional info region */
  newPlay.overlayContentStyle();

  newPlay.addExploreFilters();
  
  /* Make sure embed code interaction works with ajax content */
  newPlay.embedInteraction();
  newPlay.shareLinkInteraction();
  
  
  /*
   * Styling and cycling the main page firehose
   */
  $('#feeds-wrapper .item-list ul').each(function() {
    $(this).cycle({
      pause: 1,
      random: 1
    });
  });
  
  $('#feeds-wrapper .item-list ul').each(function() {
    $(this).cycle('pause');
  });
};



/*
 * Main Document Ready
 */
$(document).ready(function() {
  if ($('.redirect-path').length > 0) {
    var path = $('.redirect-path').attr('href');
    newPlay.redirectToMapInit(path);
  }
  
  // Allow rel=external to avoid non-semantic target values
  $('[rel=external]').attr('target', '_blank');
  
/*   width = $(window).width() - 200; */
    width = 300;
   /**
    * Make a close box for the overlay filter
    */
    
   var filtersContent = $('#block-views--exp-organizations-panel_pane_1 .content');
   /*
$('<a></a>').attr({
     'title': 'close',
     'href': '#'
   }).html('Close')
     .addClass('newplay-close-box')
     .click(function() {
       $('#filter_button').trigger('click');
     })
     .appendTo(filtersContent);
*/
    
/*
    $(filtersContent).find('.views-exposed-widgets .views-exposed-widget:last').prependTo($(filtersContent).find('.views-exposed-widgets')).attr('id', 'filter-submit');
   
*/ 
/*    newPlay.formatLinksBubble($('#block-views--exp-organizations-panel_pane_1'), 'filter_button', width); */
   
   newPlay.formatLinksBubble($('#block-invite-0'), 'invite_button');
    
  
  /*
   * Dialog for first time logins
   * Drupal.settings.newplay.firstLogin == true used to come out of the module but
   * was unreliable
   * @TODO: delete this if nothing else is broken
   */
  // if (($('body.logged-in').length > 0) && (!$.cookie('new-user')) && ($('body.front').length > 0)) {
  //   $('#block-block-4 .content').dialog({ 
  //     modal: true,
  //     title: $('#block-block-4').find('h2'),
  //     width: 400,
  //     resizable: false,
  //     draggable: false,
  //     close: function(event, ui) {
  //       $('#feeds-wrapper .item-list ul').cycle('resume');
  //     }
  //     
  //   });
  //   $.cookie('new-user', false, {expires: 365, domain: 'newplaymap.quilted.coop', path: '/'});
  // } else {
  //   $('#feeds-wrapper .item-list ul').cycle('resume');
  // }
  
  
  /*
   * Dialog prompt to add feeds
   * 
   */
   // if (($('body.node-type-organization').length > 0)) {  
  if (($('body.node-type-organization').length > 0) && ($('.pane-block-5').length > 0) && !$.cookie('feed-prompt')) {
    $('.pane-block-5 .pane-content').clone().dialog({ 
      modal: true,
      title: $('.pane-block-5').find('h2'),
      width: 400,
      resizable: false,
      draggable: false
      
    });
    $.cookie('feed-prompt', true, {expires: 365, domain: 'newplaymap.org', path: '/'});
  }
  
  
  /*
   * Organization form cleanup
   */
  // Set up "Other" fields
  // newPlay.initOtherField(checkboxWrapper, otherField)
  newPlay.initOtherField($('#edit-taxonomy-7-271-wrapper'), $('#edit-taxonomy-tags-8-wrapper'));
  newPlay.initOtherField($('#edit-taxonomy-3-280-wrapper'), $('#edit-taxonomy-tags-9-wrapper'));
  
  /*
   *
   */
  // hide the text of the openid link so it's less obtrusive but people that want it (i.e. me) can use it
  $('.openid-link a').text('').attr('title', 'Log in using OpenID');
  
  
  
  /**
   * Override of autocomplete.js function Drupal.jsAC.prototype.select()
   * Puts the currently highlighted suggestion into the autocomplete field
   */
  // Make sure that one of the fields we want is on the page
  var availableFields = $('#edit-field-related-theater-nid-nid').length + $('#edit-field-artist-nid-nid').length;
  
  if (availableFields > 0) {
    Drupal.jsAC.prototype.select = function (node) {
      this.input.value = node.autocompleteValue;
      
      if (this.input.id == 'edit-field-related-theater-nid-nid') {
        newPlay.autocomplete.org(node); 
      } else if (this.input.id == 'edit-field-artist-nid-nid') {
        newPlay.autocomplete.artist(node);
      }
    };
  }
  
  
  /*
   * Code to handle selecting the autocomplete option using the Return or Tab key
   * (for some reason Drupal.jsAC.prototype.select doesn't fire in those cases)
   */
   $('#edit-field-related-theater-nid-nid').blur(function() {
     var node = {};
     node.autocompleteValue = $('#edit-field-related-theater-nid-nid').val();
     newPlay.autocomplete.org(node);
   });
   
   
  /*
   * Universal Add Button
   */
  newPlay.formatLinksBubble($('#block-add_button-0'), 'add_button');
    

	/*
	 * Display of Contact info field on forms
	 */
	if ($('#edit-field-related-theater-nid-nid').hasClass('error')) {
		$('#edit-field-related-theater-nid-nid').removeClass('error');
		$('#edit-add-org-contact-wrapper').show().find('#edit-add-org-contact').addClass('error');
	} 
  
  
  /*
   * Altering forms to work with Contact / Invite system
   * @TODO: Add the validation from the validation jquery plugin
   *        It will help with saving the name and email data if other
   *        required fields aren't filled out
   */   
  if ($('#node-form').length > 0) {
    // Get some info so we know which form we're on
    newPlay.formAction = $('#node-form').attr('action');
    
    // the arguments for newPlay.findFormId are the form action string, the base path, and the body classes
    newPlay.formId = newPlay.findFormId(newPlay.formAction, Drupal.settings.basePath, $('body').attr('class'));
    
    
    
    /** Deal with forms by content type **/
    /*
     * all feed forms
     */
    if (newPlay.formId == 'twitter-feed' || newPlay.formId == 'blog-feed' || newPlay.formId == 'photo-feed' || newPlay.formId == 'video-feed') {
      if ($('#edit-field-related-theater-nid-nid').val().length == 0) {
        $('#edit-field-related-theater-nid-nid-wrapper').hide();
      }
      
      if ($('#edit-field-related-play-nid-nid-wrapper').val().length == 0) {
        $('#edit-field-related-play-nid-nid-wrapper').hide();
      } 
      
      if ($('#edit-field-artist-nid-nid-wrapper').val().length == 0) {
        $('#edit-field-artist-nid-nid-wrapper').hide();
      }
      
      // Uncomment to also hide the autopopulated related nodes
      // $('#edit-field-artist-0-nid-wrapper').hide();
      // $('#edit-field-related-theater-0-nid-wrapper').hide();
      // $('#edit-field-related-play-0-nid-wrapper').hide();
    }
    
    /*
     * Org and Artist pages
     */
    if (newPlay.formId == 'organization' || newPlay.formId == 'artist') {
      // Use custom autocomplete display
      newPlay.autocompleteEditSuggestions();
      
      $('#node-form').validate();
    }
    
    
    /*
     * Play Pages
     */
    if (newPlay.formId == 'play') {
      $('#node-form').validate();
      
      // @TODO: Refactor to merge with line 412 above (the org and artist version of this same function)

      $('#edit-field-artist-nid-nid').blur(function() {
        if ($(this).val().length > 0) {
          // $(this).parent() is edit-field-artist-nid-nid-wrapper
          newPlay.validateContactPlay('artist', $(this).parent(), $(this).siblings('.contact-wrapper').find('.contact-name-field').val(), $(this).siblings('.contact-wrapper').find('.contact-email-field').val(), $(this).val(), false);
        }
      });

      $('#node-form').submit(function() {
        // Disable to submit button to prevent dupes
        $('#node-form').find('#edit-submit').attr({
          'disabled': 'disabled',
          'value': 'Processing...'
          });
        
        var submit = false;

        // If the form is valid, doing our server validation and create the user
        // Otherwise just do the normal validation without creating the user
        var valid = ($('#node-form').valid()) ? true : false;

        var name = $('#edit-field-artist-nid-nid').siblings('.contact-wrapper').find('.contact-name-field').val();

        var email = $('#edit-field-artist-nid-nid').siblings('.contact-wrapper').find('.contact-email-field').val() || 'undefined';

        var nodeId = $('#edit-field-artist-nid-nid').val().replace(/.*nid:/, '').replace(']', '');
      
        $.ajax({
          url: Drupal.settings.basePath + 'newplay_reference/node/' + 'artist' + '/' + name + '/' + email + '/' + nodeId + '/' + valid,
          dataType: 'json',
          async: false,
          success: function(data) {
            newPlay.validateContact.data = data;
            // do stuff with the data
            if (newPlay.validateContact.data.ready_to_submit == true) {
              submit = true;
            } else {
              submit = false;
              $('#node-form').find('#edit-submit').removeAttr('disabled').attr('value', 'Submit');
            }
          }
        });
        
        return submit;        
      });

    }
    
    
    /*
     * Event page
     */
    if (newPlay.formId == 'event') {
      // @TODO: Refactor to merge with similar code for the other pages

      $('#edit-field-related-theater-nid-nid').blur(function() {
        // Only try to validate when there is text in the field
        if ($(this).val().length > 0) {
          newPlay.validateContactOrg($(this).parent(), $(this).siblings('.contact-wrapper').find('.contact-name-field').val(), $(this).siblings('.contact-wrapper').find('.contact-email-field').val(), $(this).val(), false);
        }
      });
      
      // There is a problem with hitting return and the validation plugin
      // snagging focus before submit gets called
      // This should probably be done some other way but I couldn't
      // get a key listening setup working
      $('#edit-field-related-theater-nid-nid').focus(function() {
        $('#edit-field-related-play-nid-nid-wrapper input:visible:last').trigger('blur');
      });
      
      newPlay.enableReturnKey($('#edit-field-related-play-nid-nid'));
      newPlay.enableReturnKey($('#edit-value'));
      
      newPlay.enableReturnKey($('#edit-field-related-theater-nid-nid'));
      
      
      $('#edit-field-related-play-nid-nid').blur(function() {
        if ($(this).val().length > 0) {
          newPlay.validateContactPlayEvent($(this).parent(), $(this).siblings('.contact-wrapper').find('.contact-name-field').val(), $(this).siblings('.contact-wrapper').find('.contact-email-field').val(), $(this).val(), false);
        }
      });
      


      $('#node-form').submit(function() {
        // Disable to submit button to prevent dupes
        $('#node-form').find('#edit-submit').attr({
          'disabled': 'disabled',
          'value': 'Processing...'
          });
        
        var submit = false;
        var orgDefault = ($('#edit-field-related-theater-nid-nid').length > 0) ? false : true;
        var playDefault = ($('#edit-field-related-play-nid-nid').length > 0) ? false : true;
        
        newPlay.orgSubmit = newPlay.orgSubmit || orgDefault;
        newPlay.playSubmit = newPlay.playSubmit || playDefault;
                
        newPlay.validatePlayContact = newPlay.validatePlayContact || {};
        newPlay.validateOrgContact = newPlay.validateOrgContact || {};
        
        // To prevent multiple submits
        if (newPlay.orgSubmit === true && newPlay.playSubmit === true) {
          return false;
        }

        // Custom validation function
        // It sets the errors and returns true if valid
        var valid = newPlay.formValidation($('#node-form'));
        
        if ($('#edit-field-related-theater-nid-nid').length > 0) {
          var orgName = $('#edit-field-related-theater-nid-nid').siblings('.contact-wrapper').find('.contact-name-field').val();

          var orgEmail = $('#edit-field-related-theater-nid-nid').siblings('.contact-wrapper').find('.contact-email-field').val() || 'undefined';

          var orgNodeId = $('#edit-field-related-theater-nid-nid').val().replace(/.*nid:/, '').replace(']', '');
          $.ajax({
            url: Drupal.settings.basePath + 'newplay_reference/node/' + 'organization' + '/' + orgName + '/' + orgEmail + '/' + orgNodeId + '/' + valid,
            dataType: 'json',
            async: false,
            success: function(data) {
              newPlay.validateOrgContact.data = data;
              // do stuff with the data
              if (newPlay.validateOrgContact.data.ready_to_submit === true) {
                newPlay.orgSubmit = true;
              } else {
                newPlay.orgSubmit = false;
              }
            }
          });
        }
        
        if ($('#edit-field-related-play-nid-nid').length > 0) {
          var playContactName = $('#edit-field-related-play-nid-nid').siblings('.contact-wrapper').find('.contact-name-field').val() || 'undefined';

          var playEmail = $('#edit-field-related-play-nid-nid').siblings('.contact-wrapper').find('.contact-email-field').val() || 'undefined';

          var playNodeId = $('#edit-field-related-play-nid-nid').val().replace(/.*nid:/, '').replace(']', '');

          var artist = $('#edit-value').val().replace(/.*nid:/, '').replace(']', '') || 'undefined';

          $.ajax({
            url: Drupal.settings.basePath + 'newplay_reference/play/' + 'play' + '/' + playContactName + '/' + playEmail + '/' + playNodeId + '/' + artist + '/' + valid,
            dataType: 'json',
            async: false,
            success: function(data) {
              newPlay.validatePlayContact.data = data;            
              // do stuff with the data
              if (newPlay.validatePlayContact.data.ready_to_submit === true) {
                newPlay.playSubmit = true;
              } else {
                newPlay.playSubmit = false;
              }
            }
          });
        }
        
        
        // console.log('after ajax - newPlay.orgSubmit: ' + newPlay.orgSubmit);
        // console.log('after ajax - newPlay.playSubmit: ' + newPlay.playSubmit);
        if (newPlay.orgSubmit === true && newPlay.playSubmit === true) {
          // console.log('true');
          return true;
        } else {
          // console.log('false');
          // Revalidate Org field
          var orgField = $('#edit-field-related-theater-nid-nid');
          // Only try to validate when there is text in the field
          if ($(orgField).val().length > 0) {
            newPlay.validateContactOrg($(orgField).parent(), $(orgField).siblings('.contact-wrapper').find('.contact-name-field').val(), $(orgField).siblings('.contact-wrapper').find('.contact-email-field').val(), $(orgField).val(), false);
          }

          // @TODO: Revalidate Play field also.

          $('#node-form').find('#edit-submit').removeAttr('disabled').attr('value', 'Submit');
          return false;
        }
        // return submit;
      });  
      
    }
    
    
    /**
     * Stuff we want processed on all forms but AFTER the individual processes happen
     */
    // This is causing dupes
    newPlay.returnSubmit($('#node-form'));
  }
  
  
  /**
   * Automating selection of some exposed filter elements
   */
  $('form#views-exposed-form-organizations-panel-pane-1').find('#edit-partner-org-wrapper, #edit-org-id, #edit-artist-id, #edit-play-title-wrapper').parents('.views-exposed-widget').addClass('auto-populate');
  
  // Turn Ensemble text field into a checkbox
  var ensemble = $('#edit-ensemble').hide();
  var ensembleCheckbox = $('<input type="checkbox"></input>').attr('id', 'edit-ensemble-checkbox').insertAfter(ensemble);
  
  if (ensemble.val() == 1) {
    ensembleCheckbox.attr('checked', true);
  }
  
  $('form#views-exposed-form-organizations-panel-pane-1').submit(function() {
    
    // Set up general variable for org (controlled by related theater field)
    // to use for a few other fields
    var org = $(this).find('#edit-theater option:selected').attr('value');
    org = (org != 'All') ? org : '';
    
    // Set the partner field based on the related theater field
    $(this).find('#edit-partner-org-wrapper option[value=' + org + ']').attr('selected', true);
    
    // Set the Org NID field based on the related theater field
    $(this).find('#edit-org-id').val(org);
    
    // Set up general variable for artist (controlled by related artist field)
    //  to use for a few other fields
    var artist = $(this).find('#edit-artist option:selected').attr('value');
    artist = (artist != 'All') ? artist : '';
    
    // Set the Artist NID based on the related artist field
    $(this).find('#edit-artist-id').val(artist);

    // Set up play variable
    var play = $(this).find('#edit-play').attr('value');
    play = (play != 'All') ? play : '';

    // Set the Play NID based on the related artist field
    $(this).find('#edit-play-title').val(play);
    
    // Use new checkbox field to populate text field
    var ensembleChecked = ($('#edit-ensemble-checkbox').attr('checked')) ? '1' : '';
    $(this).find('#edit-ensemble').val(ensembleChecked);
    
  });
  
  
  /**
   * Make a close box for the messages
   */
  $('<a></a>').attr({
    'title': 'close',
    'href': '#'
  }).html('Close')
    .addClass('newplay-close-box')
    .click(function() {
      $(this).parent().fadeOut();
    })
    .prependTo('div.messages');

  
  /**
   * Format the home page overlay listings
   */
  if ($('.filter-results-listing').length > 0) {

    var todayHeaderList = $('<ul></ul>').addClass('overlay-filter-headers').insertAfter('#panel-default-overlay .overlay-title');
    
    
    $('#panel-default-overlay .filter-results-listing').each(function() {
      // If there are items in the list, count them, otherwise return empty string
      var itemCount = $(this).find('.item-list li').not(':empty').length;
      var itemCountText = itemCount > 0 ? '<strong>' + itemCount + '</strong> ' : '';
      var listingPaneId = $(this).attr('id'); // Grab the id for this list to use later
      var itemHeaderTitle = $(this).children('h2.pane-title').remove().html();

      if ((itemCount <= 1) && (itemHeaderTitle.substr(itemHeaderTitle.length-1, 1) == 's')) {
        itemHeaderTitle = itemHeaderTitle.substr(0, itemHeaderTitle.length-1);
      }

      // Create a list item for each Results section
      $('<li></li>')
        .attr({
          'id': listingPaneId + '-title'
        })
        .html('<a>' + itemCountText + itemHeaderTitle + '</a>') // Grab the title of each list and remove it from original location
        .click(function() {
          // Hide and show different What's on Today listings
          // and set active classes
          $('.overlay-filter-headers li').not('#' + listingPaneId + '-title').removeClass('active');
          $('#panel-default-overlay .filter-results-listing').not('#' + listingPaneId).fadeOut('normal', function() {
            $('#' + listingPaneId).fadeIn();
            $('#' + listingPaneId + '-title').addClass('active');
          });

          /* // If this is the events list and the user has filtered the map
          if (listingPaneId == 'filter-results-events' && newPlay.queryString.length > 1) {
            // show all the events that the filter returned
            newPlay.layerToggle('all-events', false);
          } else {
            // otherwise show what's on today events
            newPlay.layerToggle(listingPaneId, false);
          } */

        })
        .appendTo(todayHeaderList);
    });
    
    $('.filter-results-listing:first').fadeIn();
    $('.overlay-filter-headers li:first').addClass('active');
    
    // For each layer, get the list of items in the panel and turn on & off features if they are present.
    // Then connect show hide button to it.

    // Check if the filters have been used

    if (newPlay.queryString.length > 1 || Drupal.openlayers.popup.jqueryAddressHashPath() != false) {
      // If so turn on all the layers
      newPlay.layerToggle('all-events', true);
      newPlay.layerToggle('filter-results-organizations', true);
      newPlay.layerToggle('filter-results-artists', true);
      
    } else {
      // otherwise show events.
      newPlay.layerToggle('filter-results-events', false);
    }

  }


// the end  
});



newPlay.layerToggle = function(listingPaneId, layersOn) {
  // Toggle Layer on and off.

  // Store the context for later use.
  var context = Drupal.openlayers.context;

  // From default OpenLayers popup functionality
  var layers, data = $(context).data('openlayers');
  if (data) {
    var map = data.openlayers;
    var options = data.map.behaviors['openlayers_newplay_behavior_popup_interaction'];
    var layers = new Array();

    // For backwards compatiability, if layers is not
    // defined, then include all vector layers
    if (typeof options.layers == 'undefined' || options.layers.length == 0) {
      layers = map.getLayersByClass('OpenLayers.Layer.Vector');
    }
    else {
      for (var i in options.layers) {
        var selectedLayer = map.getLayersBy('drupalID', options.layers[i]);
        if (typeof selectedLayer[0] != 'undefined') {
          layers.push(selectedLayer[0]);
          if(layersOn) {
          
          }
          else {
            selectedLayer[0].setVisibility(false);
          }
        }
      }
    }
    // If today link list has class active, show the layer.
    for (var i in layers) {
      switch(listingPaneId) {
        case 'all-events':
            if (layers[i]["drupalID"] === 'organizations_openlayers_2') {
              layers[i].setVisibility(true);
            }
            if (layers[i]["drupalID"] === 'organizations_openlayers_4') {
              layers[i].setVisibility(false);
            }
          break;
        case 'filter-results-events':
            if (layers[i]["drupalID"] === 'organizations_openlayers_4') {
              layers[i].setVisibility(true);
/*               newPlay.hideSelectedFeaturesByAttribute(layers[i], i, 'name', 'href', 'div.pane-views-panes div.views-field-field-related-play-nid a'); */
            }
            if (layers[i]["drupalID"] === 'organizations_openlayers_2') {
              layers[i].setVisibility(false);
            }
          break;
        case 'filter-results-organizations':
            if (layers[i]["drupalID"] === 'organizations_openlayers_1') {
             layers[i].setVisibility(true);
            }
            if (layers[i]["drupalID"] === 'organizations_openlayers_4') {
              layers[i].setVisibility(false);
            }
          break;
        case 'filter-results-artists':
            if (layers[i]["drupalID"] === 'organizations_openlayers_3') {
              layers[i].setVisibility(true);
            }
            if (layers[i]["drupalID"] === 'organizations_openlayers_4') {
              layers[i].setVisibility(false);
            }
          break;
      }
    }
  }
  return false;
};

/**
 * This function still under construction 6/1/2011 - chach
 */
newPlay.hideSelectedFeaturesByAttribute = function(layer, layerOrder, attribute, type, source) {
  //  layer.features
  var selectedFeatures = Array();
  var sourceValues = Array();
// Actually switching the search around - search for items in the list
// that would be faster than searching all the features


  // Search source, push values in an array
  $(source).each(function(){ 
    if(type == 'href') {
      sourceValue = $(this).attr('href');
    }
    sourceValues.push(sourceValue);
  });
  for (var i in layer.features) {
    if (i < 30) {  // temporary limits
      feature = layer.features[i];
      value = feature.attributes[attribute];

      if(type == 'href') {
        value = $(value).attr('href');
      }

      // Load up the source value array and compare it to the feature.
      for (var s in sourceValues) {
        // See if value matches source's value.
        if(value === sourceValues[s]) {
          // If so, add it to an array to handle the displaying of the features.
          feature.renderIntent = "dimmed";
          feature.state = "dimmed";
          feature.attributes.state = "dimmed";
          selectedFeatures.push(feature);
        }
        else {
          feature.renderIntent = "dimmed";
          feature.state = "dimmed";
          feature.attributes.state = "dimmed";

        }
      }
    }
  }

/*   Drupal.openlayers.popup.newPlayRedrawLayer(layer, layerOrder); */
  return false;
};

newPlay.layerItemSelection = function() {

  var map = $(Drupal.openlayers.context).data('openlayers');
  var layers = map.layers;
  var list;
  for (var i in layers) {
      layer = layers[i]["drupalID"];
      switch(layer) {
        case 'organizations_openlayers_1':
          list = $(this).find('div.views-field-field-event-type-nid span.field-content a').value;
          newPlay.hideSelectedFeatures(layer, list, 'field_event_type_nid_rendered');
          break;
        case 'organizations_openlayers_2':
          break;
        case 'organizations_openlayers_3':
          break;
        case 'organizations_openlayers_4':
          break;
      }
    }


/*
  $('div#panel-default-overlay div.pane-views-panes div.item-list li').each(function(){
   // var playValue = $(this).find('div.views-field-field-related-play-nid span.field-content a').value;
   // var artistValue = $(this).find('div.views-field-field-artist-nid span.field-content a').value;
   // var organizationValue = $(this).find('div.views-field-field-related-theater-nid span.field-content a').value;
  });
*/
};


newPlay.redirectToMapInit = function(path) {
  var count = parseFloat($('.redirect-countdown').text());
  newPlay.redirectToMapCountdown(count, path);
}

newPlay.redirectToMapCountdown = function(count, path) {
  if (count <= 0) {
    newPlay.redirectToMap(path);
   }
   else {
    $('.redirect-countdown').text(count);
    count--;
    setTimeout('newPlay.redirectToMapCountdown(' + count + ', "' + path + '")', 1000);
   }
}

newPlay.redirectToMap = function(path) {
  window.location = path;
}