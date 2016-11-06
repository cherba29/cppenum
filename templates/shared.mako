<%def name="open_ifdef(name)">\
% if name:
#ifdef ${name}
% endif
</%def>\
<%def name="close_ifdef(name)">\
% if name:
#endif // ${name}
% endif
</%def>\
