from django.contrib import admin
from import_export import resources
from movierecommendation.models import DoubanMovie,QuestionAmswerKB,QuestionIndex
from import_export.admin import ImportExportModelAdmin

# Register your models here.
class MovieResource(resources.ModelResource):

    class Meta:
        model = DoubanMovie
        export_order = ('movie_url','movie_title','movie_keywords','movie_description','movie_directors','movie_actors')

@admin.register(DoubanMovie)
class MovieAdmin(ImportExportModelAdmin):
    list_display = ('movie_url','movie_title','movie_keywords','movie_description','movie_directors','movie_actors')
    search_fields = ('movie_title','movie_keywords','movie_description','movie_directors','movie_actors')  
    resource_class = MovieResource
    
class QuestionAnswerResource(resources.ModelResource):

    class Meta:
        model = QuestionAmswerKB
        export_order = ('question','answer')

@admin.register(QuestionAmswerKB)
class QuestionAnswerAdmin(ImportExportModelAdmin):
    list_display = ('question','answer')
    search_fields = ('question',)  
    resource_class = QuestionAnswerResource

class IndexResource(resources.ModelResource):
    class Meta:
        model = QuestionIndex
        export_order = ('keyword', 'doclist')

@admin.register(QuestionIndex)
class QuestionIndexAdmin(ImportExportModelAdmin):
    list_display = ('keyword', 'doclist')
    search_fields = ('keyword', 'doclist')
    resource_class = IndexResource
