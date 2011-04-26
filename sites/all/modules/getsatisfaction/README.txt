/* $Id: README.txt,v 1.3 2008/12/11 20:44:32 flevour Exp $ */

-- SUMMARY --

The Get Satisfaction module provides services to better integrate Drupal with 
Get Satisfaction widgets system.
You can easily configure it to display the "Feedback" tab or use the provided 
filter which displays the Feedback page.


For a full description of the module, visit the project page:
  http://drupal.org/project/getsatisfaction

To submit bug reports and feature suggestions, or to track changes:
  http://drupal.org/project/issues/getsatisfaction

For more info about the Get Satisfaction widgets, visit the page:
  http://getsatisfaction.com/widgets

-- REQUIREMENTS --

None.


-- INSTALLATION --

* Install as usual, see http://drupal.org/node/70151 for further information.


-- CONFIGURATION --

* Configure user permissions in Administer >> User management >> Permissions >>
  getsatisfaction module:

  - adiminister get satisfaction

    Users in roles with the "administer get satisfaction" permission will be 
    able to configure the module site-wide.

* Customize the menu settings in Administer >> Site configuration >>
  Get Satisfaction.

* This module also provides a filter which you can enable at 
  admin/settings/filters. It provides a special tag [getsatisfaction-page] 
  which displays the Get Satisfaction feedback page. For more info have a look 
  at http://getsatisfaction.com/widgets . This filter adds special HTML code to
  the content, so make sure to re-arrange the filters order so that it runs last
  or at least after HTML filter.


-- CONTACT --

Current maintainers:
* Francesco Levorato (flevour) - http://drupal.org/user/1920

This project has been sponsored by: 
  CallingGuides - Using Drupal to build a network of international calling guides
  http://www.callingguides.com

-- THANKS --
Special thanks go to Mike Carter <www.ixis.co.uk/contact>, mantainer of the 
Google Analytics module, from which this module borrows a lot of code.


